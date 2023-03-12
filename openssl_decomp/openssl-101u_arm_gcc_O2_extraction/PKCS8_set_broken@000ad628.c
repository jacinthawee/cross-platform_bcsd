
PKCS8_PRIV_KEY_INFO * PKCS8_set_broken(PKCS8_PRIV_KEY_INFO *p8,int broken)

{
  if (broken == 0) {
    p8->broken = 0;
    return p8;
  }
  if (broken == 1) {
    p8->broken = 1;
    p8->pkey->type = 0x10;
    return p8;
  }
  ERR_put_error(6,0x70,0x75,"evp_pkey.c",0xa4);
  return (PKCS8_PRIV_KEY_INFO *)0x0;
}

