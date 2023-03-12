
ASN1_INTEGER * c2i_ASN1_INTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  uchar uVar1;
  uchar *__dest;
  size_t sVar2;
  ASN1_INTEGER *a_00;
  uchar *puVar3;
  uchar *puVar4;
  int iVar5;
  uchar *__src;
  uchar *local_24;
  size_t local_20;
  
  if ((a == (ASN1_INTEGER **)0x0) || (a_00 = *a, a_00 == (ASN1_INTEGER *)0x0)) {
    a_00 = ASN1_STRING_type_new(2);
    if (a_00 == (ASN1_STRING *)0x0) {
      return (ASN1_INTEGER *)0x0;
    }
    a_00->type = 2;
    __src = *pp;
    __dest = (uchar *)CRYPTO_malloc(length + 1,"a_int.c",199);
    if (__dest == (uchar *)0x0) {
      ERR_put_error(0xd,0xc2,0x41,"a_int.c",0x103);
      if (a == (ASN1_INTEGER **)0x0) goto LAB_0813aac6;
      goto LAB_0813aabe;
    }
  }
  else {
    __src = *pp;
    __dest = (uchar *)CRYPTO_malloc(length + 1,"a_int.c",199);
    if (__dest == (uchar *)0x0) {
      ERR_put_error(0xd,0xc2,0x41,"a_int.c",0x103);
LAB_0813aabe:
      if (*a == a_00) {
        return (ASN1_INTEGER *)0x0;
      }
LAB_0813aac6:
      ASN1_STRING_free(a_00);
      return (ASN1_INTEGER *)0x0;
    }
  }
  local_24 = __src + length;
  local_20 = length;
  if (length == 0) {
    a_00->type = 2;
    goto LAB_0813a910;
  }
  if (-1 < (char)*__src) {
    a_00->type = 2;
    sVar2 = length;
    if ((*__src == '\0') && (sVar2 = 1, length != 1)) {
      sVar2 = length - 1;
      __src = __src + 1;
      local_20 = sVar2;
    }
    memcpy(__dest,__src,sVar2);
    goto LAB_0813a910;
  }
  a_00->type = 0x102;
  uVar1 = *__src;
  if (uVar1 == 0xff) {
    if (length == 1) {
      local_20 = 1;
      puVar3 = __dest;
    }
    else {
      sVar2 = length - 1;
      __src = __src + sVar2;
      puVar4 = __dest + length + -2;
      uVar1 = *__src;
      local_20 = sVar2;
      length = sVar2;
      puVar3 = puVar4;
      if (uVar1 == '\0') goto joined_r0x0813aaf7;
LAB_0813aa5c:
      puVar3 = puVar4;
      length = sVar2;
      if (sVar2 == 0) goto LAB_0813ab00;
    }
  }
  else {
    __src = __src + length + -1;
    puVar3 = __dest + length + -1;
    uVar1 = *__src;
    if (uVar1 == '\0') {
      do {
        puVar4 = puVar3 + -1;
        __src = __src + -1;
        *puVar3 = '\0';
        uVar1 = *__src;
        sVar2 = length - 1;
        length = sVar2;
        puVar3 = puVar4;
        if (uVar1 != '\0') goto LAB_0813aa5c;
joined_r0x0813aaf7:
      } while (length != 0);
LAB_0813ab00:
      *__dest = '\x01';
      __dest[local_20] = '\0';
      local_20 = local_20 + 1;
      goto LAB_0813a910;
    }
  }
  *puVar3 = -uVar1;
  if (1 < length) {
    iVar5 = 0;
    do {
      puVar3[iVar5 + -1] = ~__src[iVar5 + -1];
      iVar5 = iVar5 + -1;
    } while (iVar5 != 1 - length);
  }
LAB_0813a910:
  if (a_00->data != (uchar *)0x0) {
    CRYPTO_free(a_00->data);
  }
  a_00->data = __dest;
  a_00->length = local_20;
  if (a != (ASN1_INTEGER **)0x0) {
    *a = a_00;
  }
  *pp = local_24;
  return a_00;
}

