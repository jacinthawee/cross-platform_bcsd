
char * SSL_CIPHER_get_version(SSL_CIPHER *c)

{
  if (c == (SSL_CIPHER *)0x0) {
    return "(NONE)";
  }
  if (*(char *)&c->id != '\x03') {
    if (*(char *)&c->id != '\x02') {
      return "unknown";
    }
    return "SSLv2";
  }
  return "TLSv1/SSLv3";
}

