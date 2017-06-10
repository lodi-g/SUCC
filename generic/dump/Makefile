INSTALL_DIR := $$HOME/.local/include

all:
	@echo "Run 'make install' to install the header."
	@echo "This would allow you to #include <dump.h> anywhere."

install:
	@mkdir -vp $(INSTALL_DIR)
	@cp -v dump.h $(INSTALL_DIR)
	@echo
	@echo "Please add 'export C_INCLUDE_PATH=$$C_INCLUDE_PATH:$(INSTALL_DIR)' to your shell configuration file."
	@echo "You can now #include <dump.h>."
