#------------------------------------------------------------------------------
#----------------------	RTFI Server LibSQL Makefile	---------------------------
#------------------------------------------------------------------------------
CC		=	clang++-devel
#------------------------------------------------------------------------------
ARCHITECTURE	=	$(shell uname -m)
ifeq ($(ARCHITECTURE), i386)
ARCHITECTURE	=	x86
else
ARCHITECTURE	=	x64
endif
FREEBSD_VERSION	=	$(shell uname -v 2>&1 | cut -d' ' -f2 | cut -d'-' -f1)
#------------------------------------------------------------------------------
EXTERN_DIR	=	../../../Extern
BIN_DIR = ../../../../Server/Share/Bin
BIN		= $(BIN_DIR)/DB
SRC_DIR	=	../Srcs
OBJ_DIR = Objs
#------------------------------------------------------------------------------
$(shell if [ ! -d $(BIN_DIR) ]; then mkdir -p $(BIN_DIR); fi)
$(shell if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi)
#------------------------------------------------------------------------------
FLAGS	+=	-g
FLAGS	+=	-ggdb
FLAGS	+=	-DNDEBUG
FLAGS	+=	-w
FLAGS	+=	-m32
FLAGS	+=	-mtune=i686
FLAGS	+=	-fstack-protector
FLAGS	+=	-Wall
FLAGS	+=	-O2
FLAGS	+=	-fno-rtti
FLAGS	+=	-pipe
FLAGS	+=	-fno-exceptions
FLAGS	+=	-pthread
FLAGS	+=	-D_THREAD_SAFE
FLAGS	+=	-std=c++2a
#--Boost-----------------------------------------------------------------------
INC_DIR	+=	-I$(EXTERN_DIR)/Common/Boost_1.79.0
#--MySQL-----------------------------------------------------------------------
INC_DIR	+=	-I$(EXTERN_DIR)/FreeBSD_$(FREEBSD_VERSION)/$(ARCHITECTURE)/MySQL_5.5.62/Include
LIB_DIR	+=	-L$(EXTERN_DIR)/FreeBSD_$(FREEBSD_VERSION)/$(ARCHITECTURE)/MySQL_5.5.62/Lib
LIBS += -lmysqlclient
#--LibTheCore------------------------------------------------------------------------
LIB_DIR +=	-L../../LibTheCore/Proj/lib/FreeBSD_$(FREEBSD_VERSION)/$(ARCHITECTURE)
LIBS	+=	-lthecore
#--LibSQL------------------------------------------------------------------------
LIB_DIR +=	-L../../LibSQL/Proj/lib/FreeBSD_$(FREEBSD_VERSION)/$(ARCHITECTURE)
LIBS	+=	-lsql
#--LibPoly------------------------------------------------------------------------
LIB_DIR +=	-L../../LibPoly/Proj/lib/FreeBSD_$(FREEBSD_VERSION)/$(ARCHITECTURE)
LIBS	+=	-lpoly
#--LibGame------------------------------------------------------------------------
LIB_DIR +=	-L../../LibGame/Proj/lib/FreeBSD_$(FREEBSD_VERSION)/$(ARCHITECTURE)
LIBS	+=	-lgame
#------------------------------------------------------------------------------
SRCS	=	\
			Config.cpp						\
			NetBase.cpp						\
			Peer.cpp						\
			PeerBase.cpp					\
			Main.cpp						\
			Lock.cpp						\
			DBManager.cpp					\
			Cache.cpp						\
			LoginData.cpp					\
			ClientManager.cpp				\
			ClientManagerPlayer.cpp			\
			ClientManagerLogin.cpp			\
			ClientManagerBoot.cpp			\
			ClientManagerParty.cpp			\
			ClientManagerGuild.cpp			\
			GuildManager.cpp				\
			HB.cpp							\
			PrivManager.cpp					\
			MoneyLog.cpp					\
			ItemAwardManager.cpp			\
			ClientManagerEventFlag.cpp		\
			Marriage.cpp					\
			Monarch.cpp						\
			BlockCountry.cpp				\
			ItemIDRangeManager.cpp			\
			ClientManagerHorseName.cpp		\
			AuctionManager.cpp				\
			ProtoReader.cpp					\
			CsvReader.cpp 					
#------------------------------------------------------------------------------
OBJS	=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)
#------------------------------------------------------------------------------
SRCS_DIR	=	$(SRCS:%.cpp=$(SRC_DIR)/%.cpp)
#------------------------------------------------------------------------------
default:
	@clear
	@echo -e "\033[35mDB\033[0m\t\033[31m- Invalid usage !!!\033[0m"
	@echo -e ""
#------------------------------------------------------------------------------
cncn:	clean_bin dep $(BIN)
#------------------------------------------------------------------------------
cncn_c:	clean dep $(BIN)
#------------------------------------------------------------------------------

$(BIN): $(OBJS)
	@echo -e "\033[35mDB\t\033[0m\033[32m- Linking...\033[0m\t\t\033[32m$(BIN)\033[0m"
	@$(CXX) $(FLAGS) $(LIB_DIR) $(OBJS) $(LIBS) -o $(BIN)
#------------------------------------------------------------------------------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo -e "\033[35mDB\033[0m\t\033[1m- Compiling...\033[0m\t\t\033[32m$(<F)\033[0m"
	@$(CXX) $(FLAGS) $(INC_DIR) -c $< -o $@
#------------------------------------------------------------------------------
clean:
	@rm -f $(OBJ_DIR)/*.o
	@echo -e "\033[35mDB\t\033[0m\033[33m- Object files deleted...\033[0m"
	@rm -f $(BIN)
	@echo -e "\033[35mDB\t\033[0m\033[33m- Binary file deleted...\033[0m"
	@sleep 3
#------------------------------------------------------------------------------
clean_bin:
	@rm -f $(BIN)
	@echo -e "\033[35mDB\t\033[0m\033[33m- Binary file deleted...\033[0m"
	@sleep 3
#------------------------------------------------------------------------------
dep:
	@touch Depend
	@makedepend -fDepend $(INC_DIR) -I/usr/include/c++/3.3 -I/usr/include/c++/4.2 -p$(OBJDIR)/ $(SRCS) 2> /dev/null
	@echo -e "\033[35mDB\t\033[0m\033[33m- Dependencies updated...\033[0m"
#------------------------------------------------------------------------------
sinclude Depend
