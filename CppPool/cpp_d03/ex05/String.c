/*
** String.c for String in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d03/ex00
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Fri Jan  8 09:04:09 2016 Gwendoline Rodriguez
** Last update Fri Jan  8 22:27:20 2016 Gwendoline Rodriguez
*/

#include "String.h"


static void assign_c(struct String *this, char const *s);
static void assign_s(struct String *this, struct String const *str);
static void append_c(struct String* this, char const *ap);
static void append_s(struct String *this, struct String const *ap);
static char at(struct String *this, size_t pos);
static void clear(struct String *this);
static int size(struct String *this);
static int compare_c(struct String *this, char const *str);
static int compare_s(struct String *this, const struct String *str);
static size_t copy(struct String *this, char *s, size_t n, size_t pos);
static char const* c_str(struct String * this);
static int empty(struct String* this);
static int find_c(struct String *this, char const *str, size_t pos);
static int find_s(struct String *this, const struct String *str, size_t pos);
static void insert_c(struct String *this, size_t pos, char const *str);
static void insert_s(struct String *this, size_t pos, struct String const *str);
static int to_int(struct String *this);
/* static char **split_c(struct String *this, char separator); */
/* static struct String *split_s(struct String *this, char separator); */
static void aff(struct String *this);
/* static void join_c(struct s_String *this, char delim, char const **tab); */
/* static void join_s(struct s_String *this, char delim, struct s_String *tab); */
/* static struct s_String *substr(struct s_String *this, int offset, int length); */

void StringInit(String* this, char const * s)
{
  if (s)
    this->str = strdup(s);
  else
    this->str = NULL;

  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
  this->append_c = &append_c;
  this->append_s = &append_s;
  this->at = &at;
  this->clear = &clear;
  this->size = &size;
  this->compare_c = &compare_c;
  this->compare_s = &compare_s;
  this->copy = &copy;
  this->c_str = &c_str;
  this->empty = &empty;
  this->find_c = &find_c;
  this->find_s = &find_s;
  this->insert_c = &insert_c;
  this->insert_s = &insert_s;
  this->to_int = &to_int;
  /* this->split_c = &split_c; */
  /* this->split_s = &split_s; */
  this->aff = &aff;
  /* this->join_c = &join_c; */
  /* this->join_s = &join_s; */
  /* this->substr = &substr; */
}

static void assign_s (String *this, String const * str)
{
  if (str)
    this->str = strdup(str->str);
  else
    this->str = NULL;

}

static void assign_c (String *this, char const * s )
{
  if (s)
    this->str = strdup(s);
  else
    this->str = NULL;
}

void StringDestroy(String* this)
{
  if (this->str)
    free(this->str);
  memset(this, 0, sizeof(String));
}

static void clear(String* this)
{
  if (this)
    memset(this, 0, sizeof(String));
}

static void append_s(String* this, String const* ap)
{
  if (ap)
    strcat(this->str, ap->str);
  else
    this->str = NULL;
}

static void append_c(String* this, char const* ap)
{
  if (ap)
    strcat(this->str, ap);
  else
    this->str = NULL;
}

static char at(String* this, size_t pos)
{
  if (this && pos > strlen(this->str))
    return (-1);
  return (this->str[pos]);
}

static int size(String* this)
{
  if (!this || !this->str)
    return (-1);
  return (strlen(this->str));
}

static int compare_s(String *this, const String* str)
{
  return (strcmp(this->str, str->str));
}

static int compare_c(String *this, char const* str)
{
  return (strcmp(this->str, str));
}

static size_t copy(String* this, char* s, size_t n, size_t pos)
{
  int i;

  i = 0;
  printf("this : %s, s : %s\n", this->str, s);
  if (this->str && s)
    {
      while (n-- && pos < strlen(this->str))
	s[i++] = this->str[pos++];
    }
  printf("new str : %s\n", s);
  return i;
}

static char const* c_str (String * this)
{
  return (this->str);
}

static int empty (String* this)
{
  if (this->str && strlen(this->str) > 0)
    return (-1);
  return (1);
}

static int find_s (String* this, const String *str, size_t pos)
{
  return find_c(this, str->str, pos);
}

static int find_c (String* this, char const* str, size_t pos)
{
  if (this->str && (strlen(this->str) > pos))
    {
      if (strstr(&this->str[pos], str) != NULL)
        return ((strstr(&this->str[pos], str)) - (this->str));
    }
  return (-1);
}

static void insert_c(String * this, size_t pos, char const* str)
{
  int length;

  length = strlen(str);
  if (this->str && pos > strlen(this->str))
    return (append_c(this, str));
  /* if (((int) this->buffer - strlen(this->str) - length - 1) < 0) */
  /*   realloc(this, strlen(this->str) + length + 1); */
  strcpy(&this->str[pos] + length, &this->str[pos]);
  strncpy(&this->str[pos], str, length);
}

static void insert_s(String * this, size_t pos, String const* str)
{
  find_c(this, str->str, pos);
}

static void aff(String * this)
{
  if (this->str)
    write(1, this->str, strlen(this->str));
}

static int to_int(String *this)
{
  return atoi(this->str);
}

/* int main() */
/* { */
/*   String this; */
/*   String assign; */
/*   String begin; */
/*   String end; */
/*   char *str = strdup("hello !"); */

/*   StringInit(&this, "bonjour !"); */
/*   StringInit(&assign, "assign !"); */
/*   StringInit(&begin, "hello "); */
/*   StringInit(&end, "world !"); */

/*   printf("%s\n", this.str); */
/*   assign_s(&this, &assign); */
/*   printf("assign_s : %s\n", this.str); */
/*   assign_c(&this, "bonjour !"); */
/*   printf("assign_c : %s\n", this.str); */
/*   append_s(&begin, &end); */
/*   printf("append_s : %s\n", begin.str); */
/*   append_c(&this, " append_c marche!"); */
/*   printf("assign_c : %s\n", this.str); */
/*   printf("at : %c\n", at(&this, 2)); */
/*   printf("compare_s : %d\n", compare_s(&this, &this)); */
/*   printf("compare_c : %d\n", compare_c(&this, "truc bid")); */
/*   printf("char copied : %d\n", (int) copy(&begin, str, 5, 6)); */
/*   printf("c_str : %s\n", c_str(&this)); */
/*   printf("is empty? : %d\n", empty(&this)); */
/*   printf("find_s pos : %d\n", find_s(&this, &begin, 3)); */
/*   printf("find_c pos : %d\n", find_c(&this, "bon", 2)); */
/*   insert_c(&this, 2, "bon"); */
/*   printf("insert_c : %s\n", this.str);; */
/*   aff(&this); */
/*   printf("to_int : %d\n", to_int(&this)); */

/*   return (0); */
/* } */
