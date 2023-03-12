
ASN1_STRING * d2i_ASN1_bytes(ASN1_STRING **a,uchar **pp,long length,int Ptag,int Pclass)

{
  uchar *puVar1;
  uint uVar2;
  int iVar3;
  uchar *ptr;
  ASN1_STRING *pAVar4;
  ASN1_STRING *a_00;
  int iVar5;
  uchar *__dest;
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
  pAVar4 = (ASN1_STRING *)(uVar2 & 0x80);
  if (pAVar4 == (ASN1_STRING *)0x0) {
    if (Ptag == local_64) {
      if ((int)(uVar2 << 0x1a) < 0) {
        local_4c.p = local_6c;
        local_4c.xclass = Pclass;
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
        local_4c.error = (int)pAVar4;
        local_4c.inf = uVar2;
        local_4c.tag = Ptag;
        local_4c.pp = pp;
        if ((uVar2 & 1) != 0) goto LAB_0011026e;
        while (0 < local_4c.slen) {
          while( true ) {
            local_4c.q = local_4c.p;
            iVar3 = int_d2i_ASN1_bytes(&local_5c,&local_4c,(int)local_4c.max - (int)local_4c.p,
                                       local_4c.tag,local_4c.xclass,1,&local_4c.error);
            if (iVar3 == 0) goto LAB_001102ea;
            iVar3 = BUF_MEM_grow_clean(&local_58,local_5c->length + iVar5);
            if (iVar3 == 0) {
              local_4c.error = 7;
              goto LAB_001102ea;
            }
            memcpy(local_58.data + iVar5,local_5c->data,local_5c->length);
            if ((local_4c.inf & 1U) == 0) {
              local_4c.slen = local_4c.slen + ((int)local_4c.q - (int)local_4c.p);
            }
            iVar5 = iVar5 + local_5c->length;
            if ((local_4c.inf & 1U) == 0) break;
LAB_0011026e:
            local_4c.eos = ASN1_const_check_infinite_end
                                     (&local_4c.p,(int)local_4c.max - (int)local_4c.p);
            if (local_4c.eos != 0) goto LAB_00110280;
          }
        }
LAB_00110280:
        iVar3 = asn1_const_Finish(&local_4c);
        if (iVar3 == 0) {
LAB_001102ea:
          if (local_5c != (ASN1_STRING *)0x0) {
            ASN1_STRING_free(local_5c);
          }
          pAVar4 = (ASN1_STRING *)local_4c.error;
          if ((uchar *)local_58.data != (uchar *)0x0) {
            CRYPTO_free(local_58.data);
            pAVar4 = (ASN1_STRING *)local_4c.error;
          }
          goto LAB_0011018a;
        }
        a_00->length = iVar5;
        if (a_00->data != (uchar *)0x0) {
          CRYPTO_free(a_00->data);
        }
        a_00->data = (uchar *)local_58.data;
        if (local_5c != (ASN1_STRING *)0x0) {
          ASN1_STRING_free(local_5c);
        }
      }
      else {
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
          if ((a_00->length < (int)local_68) || (__dest = a_00->data, __dest == (uchar *)0x0)) {
            __dest = (uchar *)CRYPTO_malloc((int)(local_68 + 1),"a_bytes.c",0xe9);
            if (__dest == (uchar *)0x0) {
              pAVar4 = (ASN1_STRING *)0x41;
              goto LAB_0011018a;
            }
            if (a_00->data != (uchar *)0x0) {
              CRYPTO_free(a_00->data);
            }
          }
          memcpy(__dest,local_6c,(size_t)local_68);
          __dest[(int)local_68] = '\0';
          local_4c.p = local_68 + (int)local_6c;
          ptr = local_68;
        }
        a_00->length = (int)ptr;
        a_00->data = __dest;
        a_00->type = Ptag;
      }
      if (a != (ASN1_STRING **)0x0) {
        *a = a_00;
      }
      *pp = local_4c.p;
      return a_00;
    }
    pAVar4 = (ASN1_STRING *)0xa8;
  }
  else {
    pAVar4 = (ASN1_STRING *)0x66;
  }
LAB_0011018a:
  if ((a == (ASN1_STRING **)0x0) || (a_00 != *a)) {
    ASN1_STRING_free(a_00);
  }
  if (pAVar4 != (ASN1_STRING *)0x0) {
    ERR_put_error(0xd,0x8f,(int)pAVar4,"a_bytes.c",0xaf);
    pAVar4 = (ASN1_STRING *)0x0;
  }
  return pAVar4;
}

