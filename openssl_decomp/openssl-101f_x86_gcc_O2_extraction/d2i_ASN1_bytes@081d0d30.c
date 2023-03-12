
ASN1_STRING * d2i_ASN1_bytes(ASN1_STRING **a,uchar **pp,long length,int Ptag,int Pclass)

{
  uint uVar1;
  ASN1_STRING *pAVar2;
  int iVar3;
  ASN1_STRING *a_00;
  uchar *puVar4;
  int iVar5;
  uchar *__dest;
  int in_GS_OFFSET;
  uchar *local_6c;
  size_t local_68;
  int local_64;
  int local_60;
  ASN1_STRING *local_5c;
  BUF_MEM local_58;
  ASN1_const_CTX local_4c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((a == (ASN1_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_STRING *)0x0)) {
    a_00 = ASN1_STRING_new();
    if (a_00 == (ASN1_STRING *)0x0) {
      a_00 = (ASN1_STRING *)0x0;
      goto LAB_081d0f7f;
    }
    local_6c = *pp;
    uVar1 = ASN1_get_object(&local_6c,(long *)&local_68,&local_64,&local_60,length);
    if ((uVar1 & 0x80) == 0) goto LAB_081d0dac;
    iVar5 = 0x66;
    goto LAB_081d1035;
  }
  local_6c = *pp;
  uVar1 = ASN1_get_object(&local_6c,(long *)&local_68,&local_64,&local_60,length);
  if ((uVar1 & 0x80) == 0) {
LAB_081d0dac:
    if (local_64 != Ptag) {
      iVar5 = 0xa8;
      goto LAB_081d1035;
    }
    if ((uVar1 & 0x20) != 0) {
      local_4c.tag = Ptag;
      local_5c = (ASN1_STRING *)0x0;
      local_58.length = 0;
      local_4c.pp = pp;
      local_4c.p = local_6c;
      local_4c.max = local_6c + length;
      local_58.max = 0;
      local_58.data = (char *)0x0;
      local_4c.slen = local_68;
      local_4c.xclass = Pclass;
      if (length == 0) {
        local_4c.max = (uchar *)0x0;
      }
      iVar5 = 0;
      local_4c.inf = uVar1;
      do {
        if ((local_4c.inf & 1U) == 0) {
          if (local_4c.slen < 1) goto LAB_081d0ee7;
        }
        else {
          local_4c.eos = ASN1_const_check_infinite_end
                                   (&local_4c.p,(int)local_4c.max - (int)local_4c.p);
          if (local_4c.eos != 0) {
LAB_081d0ee7:
            iVar3 = asn1_const_Finish(&local_4c);
            if (iVar3 == 0) goto LAB_081d10cd;
            a_00->length = iVar5;
            if (a_00->data != (uchar *)0x0) {
              CRYPTO_free(a_00->data);
            }
            a_00->data = (uchar *)local_58.data;
            puVar4 = local_4c.p;
            if (local_5c != (ASN1_STRING *)0x0) {
              ASN1_STRING_free(local_5c);
              puVar4 = local_4c.p;
            }
            goto LAB_081d0f6d;
          }
        }
        local_4c.q = local_4c.p;
        pAVar2 = d2i_ASN1_bytes(&local_5c,&local_4c.p,(int)local_4c.max - (int)local_4c.p,
                                local_4c.tag,local_4c.xclass);
        if (pAVar2 == (ASN1_STRING *)0x0) {
          local_4c.error = 0xd;
          goto LAB_081d10cd;
        }
        iVar3 = BUF_MEM_grow_clean(&local_58,local_5c->length + iVar5);
        if (iVar3 == 0) goto LAB_081d1120;
        memcpy(local_58.data + iVar5,local_5c->data,local_5c->length);
        if ((local_4c.inf & 1U) == 0) {
          local_4c.slen = local_4c.slen - ((int)local_4c.p - (int)local_4c.q);
        }
        iVar5 = iVar5 + local_5c->length;
      } while( true );
    }
    if (local_68 == 0) {
      if (a_00->data == (uchar *)0x0) {
        __dest = (uchar *)0x0;
        puVar4 = local_6c;
      }
      else {
        __dest = (uchar *)0x0;
        CRYPTO_free(a_00->data);
        puVar4 = local_6c;
      }
    }
    else {
      if (a_00->length < (int)local_68) {
        if (a_00->data != (uchar *)0x0) {
          CRYPTO_free(a_00->data);
        }
LAB_081d108f:
        __dest = (uchar *)CRYPTO_malloc(local_68 + 1,"a_bytes.c",0xd5);
        if (__dest == (uchar *)0x0) {
          iVar5 = 0x41;
          goto LAB_081d1035;
        }
      }
      else {
        __dest = a_00->data;
        if (__dest == (uchar *)0x0) goto LAB_081d108f;
      }
      memcpy(__dest,local_6c,local_68);
      __dest[local_68] = '\0';
      puVar4 = local_6c + local_68;
    }
    a_00->length = local_68;
    a_00->data = __dest;
    a_00->type = local_64;
LAB_081d0f6d:
    if (a != (ASN1_STRING **)0x0) {
      *a = a_00;
    }
    *pp = puVar4;
    goto LAB_081d0f7f;
  }
  iVar5 = 0x66;
LAB_081d103d:
  if (a_00 != *a) goto LAB_081d1045;
  goto LAB_081d1051;
LAB_081d1120:
  local_4c.error = 7;
LAB_081d10cd:
  ERR_put_error(0xd,0x69,local_4c.error,"a_bytes.c",0x135);
  if (local_5c != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_5c);
  }
  if ((uchar *)local_58.data != (uchar *)0x0) {
    CRYPTO_free(local_58.data);
  }
  iVar5 = 0;
LAB_081d1035:
  if (a != (ASN1_STRING **)0x0) goto LAB_081d103d;
LAB_081d1045:
  ASN1_STRING_free(a_00);
LAB_081d1051:
  ERR_put_error(0xd,0x8f,iVar5,"a_bytes.c",0xf3);
  a_00 = (ASN1_STRING *)0x0;
LAB_081d0f7f:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a_00;
}

