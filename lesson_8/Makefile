# ---------------------------------------------------------------------------
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License version 2 as 
#  published by the Free Software Foundation.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#
#  As a special exception, you may use this file as part of a free software
#  library without restriction.  Specifically, if other files instantiate
#  templates or use macros or inline functions from this file, or you compile
#  this file and link it with other files to produce an executable, this
#  file does not by itself cause the resulting executable to be covered by
#  the GNU General Public License.  This exception does not however
#  invalidate any other reasons why the executable file might be covered by
#  the GNU General Public License.
#
# ---------------------------------------------------------------------------

CC		=  gcc
AR              =  ar
ifdef DEBUG
CFLAGS         += -Wall -g -fno-inline-functions -DDEBUG
else
CFLAGS	       += -Wall -O3
endif
INCLUDES	= -I . -I ./utils/includes
LDFLAGS 	= -L .
OPTFLAGS	= -O3 

# aggiungere qui altri targets
TARGETS		= permessi 	\
		  myfind        \
		  mycp_sc       \
		  mycp_std

.PHONY: all clean cleanall test
.SUFFIXES: .c .h

%: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(OPTFLAGS) -o $@ $< $(LDFLAGS) 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(OPTFLAGS) -c -o $@ $<

all		: $(TARGETS)

test		: mycp_sc mycp_std
		./test.sh ./mycp_sc
		./test.sh ./mycp_std
		gnuplot plot.gnp

clean		: 
	rm -f $(TARGETS)
cleanall	: clean
	\rm -f *.o *~ filein fileout *.dat plot.eps plot.pdf



