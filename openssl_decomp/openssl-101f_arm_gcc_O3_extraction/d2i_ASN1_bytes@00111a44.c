
ASN1_STRING * d2i_ASN1_bytes(ASN1_STRING **a,uchar **pp,long length,int Ptag,int Pclass)

{
  uchar *puVar1;
  uint uVar2;
  ASN1_STRING *pAVar3;
  int iVar4;
  uchar *ptr;
  int iVar5;
  uchar *__dest;
  ASN1_STRING *a_00;
  uchar *local_6c;
  uchar *local_68;
  int local_64;
  int iStack_60;
  ASN1_STRING *local_5c;
  BUF_MEM local_58;
  ASN1_const_CTX local_4c;
  
  if (((a == (ASN1_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_STRING *)0x0)) &&
     (a_00 = ASN1_STRING_new(), a_00 == (ASN1_STRING *)0x0)) {
    return (ASN1_STRING *)0x0;
  }
  local_6c = *pp;
  uVar2 = ASN1_get_object(&local_6c,(long *)&local_68,&local_64,&iStack_60,length);
  puVar1 = local_68;
  if ((int)(uVar2 << 0x18) < 0) {
    iVar5 = 0x66;
    goto LAB_00111bb4;
  }
  if (local_64 != Ptag) {
    iVar5 = 0xa8;
    goto LAB_00111bb4;
  }
  if ((int)(uVar2 << 0x1a) < 0) {
    local_4c.xclass = Pclass;
    local_4c.p = local_6c;
    local_4c.slen = (long)local_68;
    local_4c.max = local_6c + length;
    if (length == 0) {
      local_4c.max = (uchar *)length;
    }
    iVar5 = 0;
    local_5c = (ASN1_STRING *)0x0;
    local_58.length = 0;
    local_58.max = 0;
    local_58.data = (char *)0x0;
    local_4c.inf = uVar2;
    local_4c.tag = Ptag;
    local_4c.pp = pp;
    if ((uVar2 & 1) != 0) goto LAB_00111b18;
    while (0 < local_4c.slen) {
      while( true ) {
        local_4c.q = local_4c.p;
        pAVar3 = d2i_ASN1_bytes(&local_5c,&local_4c.p,(int)local_4c.max - (int)local_4c.p,
                                local_4c.tag,local_4c.xclass);
        if (pAVar3 == (ASN1_STRING *)0x0) {
          local_4c.error = 0xd;
          goto LAB_00111bee;
        }
        iVar4 = BUF_MEM_grow_clean(&local_58,local_5c->length + iVar5);
        if (iVar4 == 0) {
          local_4c.error = 7;
          goto LAB_00111bee;
        }
        memcpy(local_58.data + iVar5,local_5c->data,local_5c->length);
        if ((local_4c.inf & 1U) == 0) {
          local_4c.slen = local_4c.slen + ((int)local_4c.q - (int)local_4c.p);
        }
        iVar5 = iVar5 + local_5c->length;
        if ((local_4c.inf & 1U) == 0) break;
LAB_00111b18:
        local_4c.eos = ASN1_const_check_infinite_end
                                 (&local_4c.p,(int)local_4c.max - (int)local_4c.p);
        if (local_4c.eos != 0) goto LAB_00111b2a;
      }
    }
LAB_00111b2a:
    iVar4 = asn1_const_Finish(&local_4c);
    if (iVar4 == 0) {
LAB_00111bee:
      ERR_put_error(0xd,0x69,local_4c.error,"a_bytes.c",0x135);
      if (local_5c != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(local_5c);
      }
      if ((uchar *)local_58.data != (uchar *)0x0) {
        CRYPTO_free(local_58.data);
      }
      iVar5 = 0;
      goto LAB_00111bb4;
    }
    a_00->length = iVar5;
    if (a_00->data != (uchar *)0x0) {
      CRYPTO_free(a_00->data);
    }
    a_00->data = (uchar *)local_58.data;
    if (local_5c != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(local_5c);
    }
    goto LAB_00111b4e;
  }
  if (local_68 == (uchar *)0x0) {
    ptr = a_00->data;
    local_4c.p = local_6c;
    __dest = ptr;
    if (ptr != (uchar *)0x0) {
      CRYPTO_free(ptr);
      ptr = local_68;
      local_4c.p = local_6c;
      __dest = puVar1;
    }
  }
  else {
    if (a_00->length < (int)local_68) {
      if (a_00->data != (uchar *)0x0) {
        CRYPTO_free(a_00->data);
      }
LAB_00111c28:
      __dest = (uchar *)CRYPTO_malloc((int)(local_68 + 1),"a_bytes.c",0xd5);
      if (__dest == (uchar *)0x0) {
        iVar5 = 0x41;
LAB_00111bb4:
        if ((a == (ASN1_STRING **)0x0) || (*a != a_00)) {
          ASN1_STRING_free(a_00);
        }
        ERR_put_error(0xd,0x8f,iVar5,"a_bytes.c",0xf3);
        return (ASN1_STRING *)0x0;
      }
    }
    else {
      __dest = a_00->data;
      if (__dest == (uchar *)0x0) goto LAB_00111c28;
    }
    memcpy(__dest,local_6c,(size_t)local_68);
    __dest[(int)local_68] = '\0';
    local_4c.p = local_68 + (int)local_6c;
    ptr = local_68;
  }
  a_00->length = (int)ptr;
  a_00->data = __dest;
  a_00->type = local_64;
LAB_00111b4e:
  if (a != (ASN1_STRING **)0x0) {
    *a = a_00;
  }
  *pp = local_4c.p;
  return a_00;
}

