##---------------------------------------------------------------------------
##
## Makefile Template for Servers
##

all-common: FORCE
	@if [ "$(BUILD_SRV)" = "yes" ]; then \
		$(MAKE) $(MFLAGS) all-srv; \
	else \
		echo "run configure with $(BUILD_OPT) to build $(PROGRAMS)"; \
	fi

clean-common: FORCE
	@if [ "$(BUILD_SRV)" = "yes" ]; then \
		$(MAKE) $(MFLAGS) clean-srv; \
	else \
		echo "run configure with $(BUILD_OPT) to clean $(PROGRAMS)"; \
	fi

veryclean-common: FORCE
	@if [ "$(BUILD_SRV)" = "yes" ]; then \
		$(MAKE) $(MFLAGS) veryclean-srv; \
	else \
		echo "run configure with $(BUILD_OPT) to very clean $(PROGRAMS)"; \
	fi

lint-common: FORCE
	@if [ "$(BUILD_SRV)" = "yes" ]; then \
		$(MAKE) $(MFLAGS) lint-srv; \
	else \
		echo "run configure with $(BUILD_OPT) to lint $(PROGRAMS)"; \
	fi

5lint-common: FORCE
	@if [ "$(BUILD_SRV)" = "yes" ]; then \
		$(MAKE) $(MFLAGS) 5lint-srv; \
	else \
		echo "run configure with $(BUILD_OPT) to 5lint $(PROGRAMS)"; \
	fi

depend-common: FORCE
	@if [ "$(BUILD_SRV)" = "yes" ]; then \
		$(MAKE) $(MFLAGS) depend-srv; \
	else \
		echo "run configure with $(BUILD_OPT) to depend $(PROGRAMS)"; \
	fi

install-common: FORCE
	@if [ "$(BUILD_SRV)" = "yes" ]; then \
		$(MAKE) $(MFLAGS) install-srv; \
	else \
		echo "run configure with $(BUILD_OPT) to install $(PROGRAMS)"; \
	fi

all-srv: all-local

install-srv: all-srv install-local

lint-srv: lint-local
	$(LINT) $(DEFS) $(DEFINES) $(SRCS)

5lint-srv: lint5-local
	$(5LINT) $(DEFS) $(DEFINES) $(SRCS)

clean-srv: 	clean-local
	$(RM) $(PROGRAMS) $(XPROGRAMS) $(XSRCS) *.o a.out core

depend-srv: depend-local
	$(MKDEP) $(DEFS) $(DEFINES) $(SRCS)

veryclean-srv: 	clean-srv veryclean-local

Makefile: $(top_srcdir)/build/srv.mk
