CXX := g++

CPPFLAGS := $(shell Magick++-config --cxxflags --cppflags)
LDFLAGS := $(shell Magick++-config --ldflags --libs)

CPPFLAGS += $(shell pkg-config vterm --cflags)
LDFLAGS += $(shell pkg-config vterm --libs)

SOURCES := $(wildcard src/*.cpp)
DEPENDS := $(SOURCES:src%.cpp=deps%.d)
OBJECTS := $(DEPENDS:deps%.d=objs%.o)
BINFILE := aec-tool

all: $(BINFILE)

$(BINFILE): $(OBJECTS)
	@echo "Linking: $(BINFILE)..."
	@$(CXX) $(LDFLAGS) $(OBJECTS) -o $(BINFILE)

$(DEPENDS): deps/%.d: src/%.cpp
	@echo "Generating deps: $@"
	@$(shell printf "objs/`$(CXX) -MM $<`\n" > $@)

ifneq ($(MAKECMDGOALS),clean)
include $(DEPENDS)
endif

$(OBJECTS):
	@echo "Compiling: $@"
	@$(CXX) -c $(CPPFLAGS) $< -o $@

clean:
	@rm $(OBJECTS) $(DEPENDS) $(BINFILE) 2>/dev/null || true
