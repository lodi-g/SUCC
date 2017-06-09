INSTALL_DIR := $$HOME/.local/include

install:
	@mkdir -vp $(INSTALL_DIR)
	@cp -v dump.h $(INSTALL_DIR)
	@echo
	@echo "Please add 'export C_INCLUDE_PATH=$(INSTALL_DIR)' to your shell configuration file."
	@echo "You can now #include <dump.h> and use it everywhere."
