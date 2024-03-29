#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert( c.value >= 2 && c.value <= VALUE_ACE );
  assert( c.suit >= SPADES && c.suit <= CLUBS );
  //  return;
}

const char * ranking_to_string(hand_ranking_t r) {
  switch ( r ){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  default: break;
  }
  return "?";
}

char value_letter(card_t c) {
  assert_card_valid( c );
  char x;
  if( c.value >= 2 && c.value <= 9 )
    x = c.value + '0';
  else if ( c.value == 10)
    x = '0';
  else if ( c.value == VALUE_JACK)
    x = 'J';//74;
  else if ( c.value == VALUE_QUEEN)
    x = 'Q';//81;
  else if ( c.value == VALUE_KING)
    x = 'K';//75;
  else if ( c.value == VALUE_ACE)
    x = 'A';//65;
  else
    x = '?';
  return x;
}


char suit_letter(card_t c) {
  assert_card_valid( c );
  char x = '?';
  switch ( c.suit ){
  case SPADES: x = 's'; break;
  case HEARTS: x = 'h'; break;
  case DIAMONDS: x = 'd'; break;
  case CLUBS: x = 'c'; break;
  default: break;
  }
  return x;
  
}

void print_card(card_t c) {
  assert_card_valid( c );
  printf("%c%c", value_letter( c ), suit_letter( c ));
  return;
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if ( value_let == 'J' )//|| value_let == 'j' )
    temp.value = VALUE_JACK;
  else if ( value_let == 'Q' )//|| value_let == 'q' )
    temp.value = VALUE_QUEEN;
  else if ( value_let == 'K' )//|| value_let == 'k' )
    temp.value = VALUE_KING;
  else if ( value_let == 'A' )//|| value_let == 'a' )
    temp.value = VALUE_ACE;
  else if ( value_let == '0' )
    temp.value = 10;
  else if ( value_let >= '2' && value_let <= '9' )
    temp.value = value_let - '0';
  //else
  //  printf("Invalid card value input!"); exit(EXIT_FAILURE);

  switch( suit_let ){
    //case 'S': temp.suit = SPADES; break;
    //case 'H': temp.suit = HEARTS; break;
    //case 'D': temp.suit = DIAMONDS; break;
    //case 'C': temp.suit = CLUBS; break;
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;  
  case 'd': temp.suit = DIAMONDS; break;
  case 'c': temp.suit = CLUBS; break;
    //default: printf("Invalid suit input!"); exit(EXIT_FAILURE);
  }
  assert_card_valid( temp );
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert( c >=0 && c < 52 );
  unsigned suit = c / 13;
  unsigned value = c % 13;
  switch ( suit ){
  case 0: temp.suit = SPADES; break;
  case 1: temp.suit = HEARTS; break;
  case 2: temp.suit = DIAMONDS; break;
  case 3: temp.suit = CLUBS; break;
  }

  switch ( value ){
  case 0: temp.value = VALUE_KING; break;
  case 1: temp.value = VALUE_ACE; break;
    //case 11: temp.value =  VALUE_QUEEN; break;
    //case 12: temp.value = VALUE_JACK; break;
  default: temp.value = value; break;
  }
  return temp;
}
