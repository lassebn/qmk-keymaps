# QMK Keymaps
The keymap files for my keyboards running the QMK firmware

The repository structure is taken from [here](https://github.com/noahfrederick/qmk-keymaps/blob/df2eeb58d01ee91e9f8e00da3c3128e351a3362c/Rakefile) :raised_hands: kudos to [@noahfrederick](https://github.com/noahfrederick) :raised_hands:

## Current daily driver
My current daily driver is the [Atreus](https://github.com/technomancy/atreus)

## Repo structure
  .
  ├── LICENSE
  ├── README.md
  ├── Rakefile      # Tasks for managing QMK source
  ├── atreus        # Keyboard/keymap-specific files
  │   └── keymap.c  # Keymap implementation
  │   └── rules.mk  # Keymap make rules
  ├── ...
  └── user          # Keyboard/keymap-agnostic files
      └── lassebn.h # Global header file

## Building
The `Rakefile` manages the QMK firmware source code:

  rake ci           # Build all keymaps for CI
  rake clean        # Remove build artifacts
  rake install      # Symlink keymap files into QMK source tree
  rake qmk:install  # Install QMK dependencies
  rake qmk:update   # Update QMK firmware
  rake uninstall    # Remove symlinks from QMK source tree
