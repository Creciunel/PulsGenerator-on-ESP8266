# source ~/zephyrproject/.venv/bin/activate
# source ~/zephyrproject/zephyr/zephyr-env.sh
# ZEPHYR_TOOLCHAIN_VARIANT="zephyr"
west build -p always -b esp32_devkitc_wroom/esp32/procpu GeneratorCode
# west flash
# access COM port from WSL https://docs.espressif.com/projects/vscode-esp-idf-extension/en/latest/additionalfeatures/wsl.html