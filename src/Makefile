CXX      = g++-15
CXXFLAGS = -std=c++17 -Wall -g
TARGET   = recommend
SRCDIR   = .
OBJDIR   = obj

OBJS = $(OBJDIR)/main.o \
       $(OBJDIR)/RatingManager.o \
       $(OBJDIR)/MovieManager.o \
       $(OBJDIR)/UserManager.o \
       $(OBJDIR)/SimilarityCalculator.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean run