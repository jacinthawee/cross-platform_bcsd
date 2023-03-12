
char * EC_POINT_point2hex(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                         BN_CTX *param_4)

{
  byte bVar1;
  size_t len;
  byte *buf;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  len = EC_POINT_point2oct(param_1,param_2,form,(uchar *)0x0,0,param_4);
  if (len != 0) {
    buf = (byte *)CRYPTO_malloc(len,"ec_print.c",0x95);
    if (buf != (byte *)0x0) {
      sVar2 = EC_POINT_point2oct(param_1,param_2,form,buf,len,param_4);
      if (sVar2 != 0) {
        pcVar3 = (char *)CRYPTO_malloc(len * 2 + 2,"ec_print.c",0x9e);
        if (pcVar3 != (char *)0x0) {
          pcVar4 = pcVar3;
          pbVar6 = buf;
          do {
            pbVar5 = pbVar6 + 1;
            bVar1 = *pbVar6;
            *pcVar4 = "0123456789ABCDEF"[(int)(uint)bVar1 >> 4];
            pcVar4[1] = "0123456789ABCDEF"[bVar1 & 0xf];
            pcVar4 = pcVar4 + 2;
            pbVar6 = pbVar5;
          } while (pbVar5 != buf + len);
          pcVar3[len * 2] = '\0';
          CRYPTO_free(buf);
          return pcVar3;
        }
      }
      CRYPTO_free(buf);
    }
  }
  return (char *)0x0;
}

