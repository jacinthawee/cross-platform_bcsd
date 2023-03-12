
char * EC_POINT_point2hex(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                         BN_CTX *param_4)

{
  char cVar1;
  char *pcVar2;
  size_t len;
  byte *buf;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  len = EC_POINT_point2oct(param_1,param_2,form,(uchar *)0x0,0,param_4);
  if ((len != 0) && (buf = (byte *)CRYPTO_malloc(len,"ec_print.c",0x95), buf != (byte *)0x0)) {
    pcVar3 = (char *)EC_POINT_point2oct(param_1,param_2,form,buf,len,param_4);
    if (pcVar3 == (char *)0x0) {
      CRYPTO_free(buf);
    }
    else {
      pcVar3 = (char *)CRYPTO_malloc((len + 1) * 2,"ec_print.c",0x9e);
      if (pcVar3 == (char *)0x0) {
        CRYPTO_free(buf);
      }
      else {
        pbVar5 = buf;
        pcVar2 = pcVar3;
        do {
          pbVar4 = pbVar5 + 1;
          cVar1 = "0123456789ABCDEF"[(int)(uint)*pbVar5 >> 4];
          pcVar2[1] = "0123456789ABCDEF"[*pbVar5 & 0xf];
          *pcVar2 = cVar1;
          pbVar5 = pbVar4;
          pcVar2 = pcVar2 + 2;
        } while (pbVar4 != buf + len);
        pcVar3[(len + 0x7fffffff) * 2 + 2] = '\0';
        CRYPTO_free(buf);
      }
    }
    return pcVar3;
  }
  return (char *)0x0;
}

