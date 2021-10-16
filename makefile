#
# Edit makefile_real to change rules and config.
#

CORES := $(shell nproc)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
.PHONY: build run gdb clean

build:
	@make build -j$(CORES) -f makefile_real --no-print-directory $@

run:
	@make run -j$(CORES) -f makefile_real --no-print-directory $@

test:
	@make test -j$(CORES) -f makefile_real --no-print-directory $@

gdb:
	@make gdb -j$(CORES) -f makefile_real --no-print-directory $@

clean:
	@make clean -j$(CORES) -f makefile_real --no-print-directory $@

install:
	@make install -j$(CORES) -f makefile_real --no-print-directory $@

uninstall:
	@make uninstall -j$(CORES) -f makefile_real --no-print-directory $@

docs:
	@make docs -j$(CORES) -f makefile_real --no-print-directory $@

prep_publish: docs
publish: prep_publish
	git add .
	git commit
	git pull
	git push
push: publish
git: publish

install_deps:
	@make install_deps -j$(CORES) -f makefile_real --no-print-directory $@
deps: install_deps
setup: install_deps

endif

# mac
ifeq ($(UNAME_S),Darwin)
	@echo "Unsupported operating system due to my lack of mac devices, feel free to make a pr with a working build system"
endif

# windows
ifeq ($(OS),Windows_NT)
	@echo "Unsupported operating system due to:\n\"fuck that dll hell\" - Winter 2021"
endif
