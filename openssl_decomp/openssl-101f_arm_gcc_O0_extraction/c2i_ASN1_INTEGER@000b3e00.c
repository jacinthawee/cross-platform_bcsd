
ASN1_INTEGER * c2i_ASN1_INTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  byte *__dest;
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  uchar uVar4;
  size_t sVar5;
  ASN1_STRING *a_00;
  uchar *__src;
  uchar *puVar6;
  size_t sVar7;
  uchar *puVar8;
  
  if ((a == (ASN1_INTEGER **)0x0) || (a_00 = *a, a_00 == (ASN1_INTEGER *)0x0)) {
    a_00 = ASN1_STRING_type_new(2);
    if (a_00 == (ASN1_STRING *)0x0) {
      return (ASN1_INTEGER *)0x0;
    }
    a_00->type = 2;
  }
  __src = *pp;
  __dest = (byte *)CRYPTO_malloc(length + 1,"a_int.c",199);
  puVar8 = __src + length;
  if (__dest == (byte *)0x0) {
    ERR_put_error(0xd,0xc2,0x41,"a_int.c",0x103);
    if ((a == (ASN1_INTEGER **)0x0) || (*a != a_00)) {
      ASN1_STRING_free(a_00);
    }
    return (ASN1_INTEGER *)0x0;
  }
  sVar7 = length;
  if (length == 0) {
    a_00->type = 2;
    goto LAB_000b3e38;
  }
  if (-1 < (char)*__src) {
    a_00->type = 2;
    if ((*__src == '\0') && (length != 1)) {
      __src = __src + 1;
      length = length - 1;
    }
    memcpy(__dest,__src,length);
    sVar7 = length;
    goto LAB_000b3e38;
  }
  a_00->type = 0x102;
  uVar4 = *__src;
  if (uVar4 == 0xff) {
    pbVar2 = __dest;
    if (length != 1) {
      sVar5 = length - 1;
      puVar6 = __src + length + -1;
      pbVar3 = __dest + length + -2;
      uVar4 = __src[length + -1];
      sVar7 = sVar5;
      length = sVar5;
      __src = puVar6;
      pbVar2 = pbVar3;
      if (uVar4 == '\0') goto joined_r0x000b3f1e;
LAB_000b3ebc:
      pbVar2 = pbVar3;
      length = sVar5;
      __src = puVar6;
      if (sVar5 == 0) goto LAB_000b3f20;
    }
  }
  else {
    __src = __src + length + -1;
    pbVar2 = __dest + length + -1;
    uVar4 = *__src;
    if (uVar4 == '\0') {
      do {
        pbVar3 = pbVar2 + -1;
        *pbVar2 = 0;
        sVar5 = length - 1;
        puVar6 = __src + -1;
        uVar4 = *puVar6;
        length = sVar5;
        __src = puVar6;
        pbVar2 = pbVar3;
        if (uVar4 != '\0') goto LAB_000b3ebc;
joined_r0x000b3f1e:
      } while (length != 0);
LAB_000b3f20:
      *__dest = 1;
      __dest[sVar7] = 0;
      sVar7 = sVar7 + 1;
      goto LAB_000b3e38;
    }
  }
  *pbVar2 = -uVar4;
  if (1 < length) {
    pbVar3 = __src + -1;
    do {
      pbVar1 = pbVar3 + -1;
      pbVar2 = pbVar2 + -1;
      *pbVar2 = ~*pbVar3;
      pbVar3 = pbVar1;
    } while (pbVar1 != __src + -length);
  }
LAB_000b3e38:
  if (a_00->data != (uchar *)0x0) {
    CRYPTO_free(a_00->data);
  }
  a_00->data = __dest;
  a_00->length = sVar7;
  if (a != (ASN1_INTEGER **)0x0) {
    *a = a_00;
  }
  *pp = puVar8;
  return a_00;
}

