/* C code produced by gperf version 3.0.3 */
/* Command-line: /usr/bin/gperf -m 10 -C -G -D -t  */
/* Computed positions: -k'2-3,6,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif


/* strongSwan keywords
 * Copyright (C) 2005 Andreas Steffen
 * Hochschule fuer Technik Rapperswil, Switzerland
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <string.h>

#include "keywords.h"

struct kw_entry {
    char *name;
    kw_token_t token;
};

#define TOTAL_KEYWORDS 131
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 17
#define MIN_HASH_VALUE 18
#define MAX_HASH_VALUE 253
/* maximum key range = 236, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned char asso_values[] =
    {
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254,  15,
      104, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254,   5, 254,  18,   7,  55,
       59,   3,   9,   3,  83,   3, 254, 145,  73,  35,
       29,  84,  38,   4,  13,   3,   8,  66,   4, 254,
      254,  12,   4, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254, 254, 254, 254, 254,
      254, 254, 254, 254, 254, 254
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
      case 4:
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

static const struct kw_entry wordlist[] =
  {
    {"pfs",               KW_PFS},
    {"right",             KW_RIGHT},
    {"rightgroups",       KW_RIGHTGROUPS},
    {"left",              KW_LEFT},
    {"lifetime",          KW_KEYLIFE},
    {"rightsubnet",       KW_RIGHTSUBNET},
    {"rightikeport",      KW_RIGHTIKEPORT},
    {"rightsendcert",     KW_RIGHTSENDCERT},
    {"leftcert",          KW_LEFTCERT},
    {"keyingtries",       KW_KEYINGTRIES},
    {"keylife",           KW_KEYLIFE},
    {"leftsendcert",      KW_LEFTSENDCERT},
    {"lifebytes",         KW_LIFEBYTES},
    {"keep_alive",        KW_KEEP_ALIVE},
    {"leftgroups",        KW_LEFTGROUPS},
    {"leftrsasigkey",     KW_LEFTRSASIGKEY},
    {"leftcertpolicy",    KW_LEFTCERTPOLICY},
    {"certuribase",       KW_CERTURIBASE},
    {"lifepackets",       KW_LIFEPACKETS},
    {"rightrsasigkey",    KW_RIGHTRSASIGKEY},
    {"leftprotoport",     KW_LEFTPROTOPORT},
    {"uniqueids",         KW_UNIQUEIDS},
    {"rightallowany",     KW_RIGHTALLOWANY},
    {"virtual_private",   KW_VIRTUAL_PRIVATE},
    {"leftca",            KW_LEFTCA},
    {"rightsubnetwithin", KW_RIGHTSUBNETWITHIN},
    {"strictcrlpolicy",   KW_STRICTCRLPOLICY},
    {"type",              KW_TYPE},
    {"interfaces",        KW_INTERFACES},
    {"rightsourceip",     KW_RIGHTSOURCEIP},
    {"leftnexthop",       KW_LEFTNEXTHOP},
    {"rightprotoport",    KW_RIGHTPROTOPORT},
    {"mark_in",           KW_MARK_IN},
    {"reqid",             KW_REQID},
    {"inactivity",        KW_INACTIVITY},
    {"margintime",        KW_REKEYMARGIN},
    {"marginbytes",       KW_MARGINBYTES},
    {"rightid",           KW_RIGHTID},
    {"marginpackets",     KW_MARGINPACKETS},
    {"leftnatip",         KW_LEFTNATIP},
    {"rightcert",         KW_RIGHTCERT},
    {"me_peerid",         KW_ME_PEERID},
    {"ocspuri",           KW_OCSPURI},
    {"esp",               KW_ESP},
    {"rightnatip",        KW_RIGHTNATIP},
    {"keyexchange",       KW_KEYEXCHANGE},
    {"rightnexthop",      KW_RIGHTNEXTHOP},
    {"rightca",           KW_RIGHTCA},
    {"overridemtu",       KW_OVERRIDEMTU},
    {"rightcertpolicy",   KW_RIGHTCERTPOLICY},
    {"leftupdown",        KW_LEFTUPDOWN},
    {"mediated_by",       KW_MEDIATED_BY},
    {"ocspuri1",          KW_OCSPURI},
    {"cacert",            KW_CACERT},
    {"leftsubnet",        KW_LEFTSUBNET},
    {"eap",               KW_EAP},
    {"crluri",            KW_CRLURI},
    {"disableuniqreqids", KW_DISABLEUNIQREQIDS},
    {"leftfirewall",      KW_LEFTFIREWALL},
    {"rightfirewall",     KW_RIGHTFIREWALL},
    {"packetdefault",     KW_PACKETDEFAULT},
    {"mobike",	           KW_MOBIKE},
    {"authby",            KW_AUTHBY},
    {"ldapbase",          KW_LDAPBASE},
    {"righthostaccess",   KW_RIGHTHOSTACCESS},
    {"mediation",         KW_MEDIATION},
    {"leftallowany",      KW_LEFTALLOWANY},
    {"crluri1",           KW_CRLURI},
    {"rightupdown",       KW_RIGHTUPDOWN},
    {"lefthostaccess",    KW_LEFTHOSTACCESS},
    {"forceencaps",       KW_FORCEENCAPS},
    {"xauth_identity",    KW_XAUTH_IDENTITY},
    {"rightauth",         KW_RIGHTAUTH},
    {"aaa_identity",      KW_AAA_IDENTITY},
    {"force_keepalive",   KW_FORCE_KEEPALIVE},
    {"rightid2",          KW_RIGHTID2},
    {"tfc",               KW_TFC},
    {"leftsubnetwithin",  KW_LEFTSUBNETWITHIN},
    {"dumpdir",           KW_DUMPDIR},
    {"nat_traversal",     KW_NAT_TRAVERSAL},
    {"leftcert2",         KW_LEFTCERT2},
    {"installpolicy",     KW_INSTALLPOLICY},
    {"mark_out",          KW_MARK_OUT},
    {"fragicmp",          KW_FRAGICMP},
    {"compress",          KW_COMPRESS},
    {"leftid",            KW_LEFTID},
    {"rightauth2",        KW_RIGHTAUTH2},
    {"eap_identity",      KW_EAP_IDENTITY},
    {"cachecrls",         KW_CACHECRLS},
    {"leftca2",           KW_LEFTCA2},
    {"pfsgroup",          KW_PFSGROUP},
    {"dpdaction",         KW_DPDACTION},
    {"charondebug",       KW_CHARONDEBUG},
    {"leftsourceip",      KW_LEFTSOURCEIP},
    {"klipsdebug",        KW_KLIPSDEBUG},
    {"charonstart",       KW_CHARONSTART},
    {"dpdtimeout",        KW_DPDTIMEOUT},
    {"ike",               KW_IKE},
    {"hidetos",           KW_HIDETOS},
    {"plutostderrlog",    KW_PLUTOSTDERRLOG},
    {"plutostart",        KW_PLUTOSTART},
    {"auth",              KW_AUTH},
    {"auto",              KW_AUTO},
    {"also",              KW_ALSO},
    {"rekey",             KW_REKEY},
    {"leftauth",          KW_LEFTAUTH},
    {"rekeyfuzz",         KW_REKEYFUZZ},
    {"ikelifetime",       KW_IKELIFETIME},
    {"xauth",             KW_XAUTH},
    {"rightca2",          KW_RIGHTCA2},
    {"prepluto",          KW_PREPLUTO},
    {"rightcert2",        KW_RIGHTCERT2},
    {"leftikeport",       KW_LEFTIKEPORT},
    {"ldaphost",          KW_LDAPHOST},
    {"crlcheckinterval",  KW_CRLCHECKINTERVAL},
    {"mark",              KW_MARK},
    {"leftid2",           KW_LEFTID2},
    {"ocspuri2",          KW_OCSPURI2},
    {"dpddelay",          KW_DPDDELAY},
    {"leftauth2",         KW_LEFTAUTH2},
    {"reauth",            KW_REAUTH},
    {"crluri2",           KW_CRLURI2},
    {"nocrsend",          KW_NOCRSEND},
    {"plutodebug",        KW_PLUTODEBUG},
    {"rekeymargin",       KW_REKEYMARGIN},
    {"pkcs11module",      KW_PKCS11MODULE},
    {"pkcs11initargs",    KW_PKCS11INITARGS},
    {"pkcs11keepstate",   KW_PKCS11KEEPSTATE},
    {"pkcs11proxy",       KW_PKCS11PROXY},
    {"modeconfig",        KW_MODECONFIG},
    {"postpluto",         KW_POSTPLUTO}
  };

static const short lookup[] =
  {
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   1,
     -1,  -1,  -1,   2,   3,  -1,   4,  -1,   5,   6,
      7,   8,   9,  -1,  10,  11,  12,  13,  14,  -1,
     15,  16,  -1,  17,  18,  19,  20,  21,  -1,  22,
     -1,  -1,  23,  -1,  24,  25,  26,  27,  -1,  28,
     29,  -1,  -1,  -1,  30,  -1,  31,  -1,  -1,  -1,
     32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
     -1,  42,  43,  44,  45,  46,  47,  48,  49,  50,
     -1,  -1,  -1,  51,  52,  53,  54,  55,  56,  57,
     58,  59,  60,  61,  62,  -1,  63,  64,  65,  66,
     -1,  67,  68,  69,  70,  71,  72,  -1,  -1,  73,
     74,  75,  76,  77,  78,  79,  -1,  -1,  80,  -1,
     81,  82,  83,  84,  -1,  -1,  85,  -1,  86,  87,
     88,  89,  90,  91,  92,  -1,  93,  -1,  94,  95,
     96,  -1,  -1,  -1,  97,  -1,  98,  -1,  -1,  99,
    100, 101, 102,  -1, 103, 104,  -1,  -1,  -1, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114,  -1,
    115,  -1, 116, 117,  -1,  -1,  -1,  -1,  -1,  -1,
    118, 119,  -1, 120,  -1,  -1,  -1,  -1,  -1,  -1,
    121,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 122,
     -1, 123,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 124,  -1,  -1,  -1,  -1,  -1,  -1,
    125,  -1, 126, 127,  -1,  -1,  -1,  -1, 128,  -1,
    129,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
     -1,  -1,  -1, 130
  };

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct kw_entry *
in_word_set (str, len)
     register const char *str;
     register unsigned int len;
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].name;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &wordlist[index];
            }
        }
    }
  return 0;
}
