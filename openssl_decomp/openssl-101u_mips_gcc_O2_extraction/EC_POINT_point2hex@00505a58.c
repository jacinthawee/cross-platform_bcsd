
char * EC_POINT_point2hex(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                         BN_CTX *param_4)

{
  char cVar1;
  undefined *puVar2;
  size_t len;
  byte *buf;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  len = EC_POINT_point2oct(param_1,param_2,form,(uchar *)0x0,0,param_4);
  if ((len != 0) &&
     (buf = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len,"ec_print.c",0x8a), buf != (byte *)0x0
     )) {
    sVar3 = EC_POINT_point2oct(param_1,param_2,form,buf,len,param_4);
    if (sVar3 != 0) {
      pcVar4 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)((len + 1) * 2,"ec_print.c",0x92);
      if (pcVar4 != (char *)0x0) {
        pcVar5 = pcVar4;
        pbVar7 = buf;
        do {
          pbVar6 = pbVar7 + 1;
          cVar1 = "0123456789ABCDEF"[*pbVar7 & 0xf];
          *pcVar5 = "0123456789ABCDEF"[(int)(uint)*pbVar7 >> 4];
          pcVar5[1] = cVar1;
          puVar2 = PTR_CRYPTO_free_006a6e88;
          pcVar5 = pcVar5 + 2;
          pbVar7 = pbVar6;
        } while (pbVar6 != buf + len);
        pcVar4[len * 2] = '\0';
        (*(code *)puVar2)(buf);
        return pcVar4;
      }
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(buf);
  }
  return (char *)0x0;
}

