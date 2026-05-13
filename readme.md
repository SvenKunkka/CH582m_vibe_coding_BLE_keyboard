# CH582m Mac-Friendly Vibe Coding Keyboard Firmware

基于官方 [CH582m_vibe_coding_BLE_keyboard](https://github.com/XiaoQiaoAI/CH582m_vibe_coding_BLE_keyboard) 项目的 Mac 兼容固件分支。

## 主要修改

### 1. 按键功能重新定义 ⌨️

从左到右四颗按键功能：

| 按键位置 | 功能 | 说明 |
|---------|------|------|
| 1 (最左) | 🎤 麦克风 | 触发语音输入 |
| 2 | ✅ 允许 | 发送 Return (回车) 键 |
| 3 | ❌ 不允许 | 发送 Escape 键 |
| 4 (最右) | ↵ 回车 | 发送 Return (回车) 键 |

### 2. 智能 RGB 灯效 🌈

**灯效模式**：彩虹波浪来回移动效果

**状态控制逻辑**：

| AI 工作状态 | 灯效表现 |
|------------|---------|
| 空闲 (无任务) | 灯光全灭 |
| 工作中 (AI 正在写代码) | 彩虹波浪来回移动动画 |
| 等待批准 | 动画冻结在当前位置 |
| 批准后 | 动画继续从冻结位置运行 |

### 3. Mac 兼容性 🍎

- 使用标准 USB HID Keyboard 协议
- HID Keycode 与 macOS 完全兼容
- 支持 Command、Option 等 Mac 特有修饰键

### 4. 拨杆功能保持不变

拨杆仍控制自动批准和手动模式切换，功能不变。

## 项目结构

```
CH582m_Mac_Firmware/
├── APP/
│   ├── sub_main/
│   │   ├── psk_ws2812.c/h        # 彩虹来回波浪灯效
│   │   └── ai_state_machine.c/h  # AI 状态机控制
│   └── hardware/
│       ├── psk_multi_button.c/h   # 按键驱动 (已修改)
│       └── mac_keyboard_map.c/h   # Mac 键盘映射
├── Profile/
└── hard_ware/
```

## 新增文件说明

### `psk_ws2812.h/c`

新增 `WS2812_RAINBOW_BOUNCE` 灯效模式，实现彩虹波浪来回移动效果：

```c
// 新增灯效枚举
enum ws2812_mode_e {
    WS2812_OFF = 0x0,
    WS2812_RAINBOW_BOUNCE,  // 新增：彩虹来回波浪
    // ... 其他模式
};

// 控制函数
void ws2812_set_bounce_paused(uint8_t paused);  // 暂停/恢复动画
uint8_t ws2812_is_bounce_paused(void);          // 查询暂停状态
```

### `ai_state_machine.h/c`

AI 工作状态机：

```c
typedef enum {
    AI_STATE_IDLE = 0,           // 空闲，灯灭
    AI_STATE_WORKING,             // 工作中，彩虹动画
    AI_STATE_WAITING_ALLOW,       // 等待批准，动画冻结
    AI_STATE_ALLOWED,             // 批准后，恢复动画
    AI_STATE_DISALLOWED           // 拒绝后，灯灭
} ai_work_state_t;
```

### `mac_keyboard_map.h/c`

Mac 键盘映射和按键处理：

```c
typedef enum {
    KEY_FUNC_MIC = 0,     // 麦克风
    KEY_FUNC_ALLOW,       // 允许 (Return)
    KEY_FUNC_DISALLOW,    // 不允许 (Escape)
    KEY_FUNC_ENTER,       // 回车 (Return)
    KEY_FUNC_POWER        // 电源键
} mac_key_function_t;
```

## 构建说明

### 环境要求

- **IDE**: MounRiver Studio
- **SDK**: WCH CH583EVT (需要从 [WCH 官网](https://www.wch.cn/downloads/CH583EVT_ZIP.html) 下载)
- **下载工具**: WCHISP Studio

### 构建步骤

1. 下载官方 SDK：`https://www.wch.cn/downloads/CH583EVT_ZIP.html`

2. 将本项目代码放到 SDK 的 `EXAM\BLE` 目录下

3. 使用 MounRiver Studio 打开工程文件：
   ```
   HID_Keyboard_582m_vibe_coding.wvproj
   ```

4. 编译项目，输出文件位于：
   ```
   obj\HID_Keyboard_582m_vibe_coding.hex
   ```

### 下载固件

1. 安装 WCHISP Studio
2. 将芯片进入 Boot 模式
3. 通过 USB 下载程序

## 与原项目的差异

| 功能 | 原项目 | 本分支 |
|------|--------|--------|
| 按键 1 | 批准 (绿色) | 麦克风 |
| 按键 2 | 拒绝 (红色) | 允许 (Return) |
| 按键 3 | 自动批准 | 不允许 (Escape) |
| 按键 4 | 回车 | 回车 (Return) |
| 灯效 | 多种渐变效果 | 彩虹来回波浪 + 状态控制 |
| 平台 | Windows | macOS (兼容 Windows) |

## 使用场景

本固件专为以下使用场景设计：

1. **AI 编程辅助工具**：配合 Claude Code、Cursor 等 AI 编程工具使用
2. **Mac 用户**：使用 Mac 进行开发的用户
3. **简洁控制**：只需要简单的允许/拒绝/回车操作

## HID Keycode 参考

本固件使用的 HID Keycode 与 USB HID Usage Table 标准一致：

- `0x28` - Return/Enter
- `0x29` - Escape
- `0xE3` - Left Command (⌘)
- `0xE4` - Right Command
- `0xE5` - Left Shift
- `0xE6` - Right Shift

## 注意事项

1. **语音输入**：麦克风键需要配合上位机软件或系统语音识别功能使用
2. **灯效控制**：AI 状态切换需要通过蓝牙或 USB 接收外部指令
3. **兼容性**：本固件使用标准 HID 协议，理论上支持 macOS、Windows、Linux

## 许可证

本项目遵循原项目的非商业开源许可证协议。

## 致谢

- 原项目：[CH582m_vibe_coding_BLE_keyboard](https://github.com/XiaoQiaoAI/CH582m_vibe_coding_BLE_keyboard)
- 芯片厂商：南京沁恒微电子股份有限公司 (WCH)
