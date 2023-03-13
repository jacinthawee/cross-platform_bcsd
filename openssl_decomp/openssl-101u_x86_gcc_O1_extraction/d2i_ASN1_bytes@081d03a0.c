
ASN1_STRING * d2i_ASN1_bytes(ASN1_STRING **a,uchar **pp,long length,int Ptag,int Pclass)

{
  uint uVar1;
  ASN1_STRING *a_00;
  ASN1_STRING *a_01;
  int iVar2;
  size_t sVar3;
  uchar *puVar4;
  uchar *__dest;
  int iVar5;
  int omax;
  int iVar6;
  int in_GS_OFFSET;
  ASN1_STRING *local_d0;
  uchar *local_b4;
  size_t local_b0;
  int local_ac;
  int local_a8;
  uchar *local_a4;
  size_t local_a0;
  int local_9c;
  int local_98;
  ASN1_STRING *local_94;
  BUF_MEM local_90;
  BUF_MEM local_84;
  ASN1_const_CTX local_78;
  ASN1_const_CTX local_4c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((a != (ASN1_STRING **)0x0) && (a_00 = *a, a_00 != (ASN1_STRING *)0x0)) {
    local_b4 = *pp;
    uVar1 = ASN1_get_object(&local_b4,(long *)&local_b0,&local_ac,&local_a8,length);
    if ((uVar1 & 0x80) == 0) {
LAB_081d0413:
      iVar5 = 0xa8;
      if (Ptag == local_ac) {
        if ((uVar1 & 0x20) != 0) {
          local_78.error = 0;
          local_78.slen = local_b0;
          local_78.pp = pp;
          local_78.p = local_b4;
          local_78.max = local_b4 + length;
          local_78.xclass = Pclass;
          local_90.length = 0;
          if (length == 0) {
            local_78.max = (uchar *)0x0;
          }
          local_78.tag = Ptag;
          local_90.max = 0;
          iVar5 = 0;
          local_90.data = (char *)0x0;
          local_d0 = (ASN1_STRING *)0x0;
          local_78.inf = uVar1;
LAB_081d0578:
          if ((local_78.inf & 1U) == 0) {
            if (local_78.slen < 1) goto LAB_081d0692;
LAB_081d058c:
            iVar2 = local_78.xclass;
            iVar6 = local_78.tag;
            omax = (int)local_78.max - (int)local_78.p;
            local_78.q = local_78.p;
            a_01 = local_d0;
            if ((local_d0 != (ASN1_STRING *)0x0) ||
               (a_01 = ASN1_STRING_new(), a_01 != (ASN1_STRING *)0x0)) {
              local_a4 = local_78.p;
              uVar1 = ASN1_get_object(&local_a4,(long *)&local_a0,&local_9c,&local_98,omax);
              if ((uchar *)(uVar1 & 0x80) == (uchar *)0x0) {
                if (iVar6 != local_9c) {
                  local_78.error = 0xa8;
                  goto LAB_081d05f8;
                }
                if ((uVar1 & 0x20) != 0) {
                  local_4c.pp = (uchar **)&local_78;
                  local_4c.tag = iVar6;
                  local_4c.error = 0;
                  local_4c.xclass = iVar2;
                  local_94 = (ASN1_STRING *)0x0;
                  local_84.length = 0;
                  local_84.max = 0;
                  local_4c.p = local_a4;
                  local_84.data = (char *)0x0;
                  local_4c.slen = local_a0;
                  local_4c.max = (uchar *)(uVar1 & 0x80);
                  if (omax != 0) {
                    local_4c.max = local_a4 + omax;
                  }
                  iVar6 = 0;
                  local_4c.inf = uVar1;
                  do {
                    if ((local_4c.inf & 1U) == 0) {
                      if (local_4c.slen < 1) goto LAB_081d0878;
                    }
                    else {
                      local_4c.eos = ASN1_const_check_infinite_end
                                               (&local_4c.p,(int)local_4c.max - (int)local_4c.p);
                      if (local_4c.eos != 0) goto LAB_081d0878;
                    }
                    local_4c.q = local_4c.p;
                    iVar2 = int_d2i_ASN1_bytes(local_4c.tag,local_4c.xclass,2,&local_4c.error);
                    if (iVar2 == 0) goto LAB_081d0a38;
                    iVar2 = BUF_MEM_grow_clean(&local_84,local_94->length + iVar6);
                    if (iVar2 == 0) {
                      local_4c.error = 7;
                      goto LAB_081d0a38;
                    }
                    memcpy(local_84.data + iVar6,local_94->data,local_94->length);
                    if ((local_4c.inf & 1U) == 0) {
                      local_4c.slen = local_4c.slen - ((int)local_4c.p - (int)local_4c.q);
                    }
                    iVar6 = iVar6 + local_94->length;
                  } while( true );
                }
                if (local_a0 == 0) {
                  if (a_01->data == (uchar *)0x0) {
                    puVar4 = (uchar *)0x0;
                    local_78.p = local_a4;
                  }
                  else {
                    puVar4 = (uchar *)0x0;
                    CRYPTO_free(a_01->data);
                    local_78.p = local_a4;
                  }
                }
                else {
                  if ((a_01->length < (int)local_a0) ||
                     (puVar4 = a_01->data, puVar4 == (uchar *)0x0)) {
                    puVar4 = (uchar *)CRYPTO_malloc(local_a0 + 1,"a_bytes.c",0xe9);
                    if (puVar4 == (uchar *)0x0) {
                      local_78.error = 0x41;
                      goto LAB_081d05f8;
                    }
                    if (a_01->data != (uchar *)0x0) {
                      CRYPTO_free(a_01->data);
                    }
                  }
                  memcpy(puVar4,local_a4,local_a0);
                  puVar4[local_a0] = '\0';
                  local_78.p = local_a4 + local_a0;
                }
                a_01->length = local_a0;
                a_01->data = puVar4;
                a_01->type = iVar6;
                sVar3 = local_a0;
                goto LAB_081d096a;
              }
              local_78.error = 0x66;
              goto LAB_081d05f8;
            }
            goto LAB_081d0621;
          }
          local_78.eos = ASN1_const_check_infinite_end
                                   (&local_78.p,(int)local_78.max - (int)local_78.p);
          if (local_78.eos == 0) goto LAB_081d058c;
LAB_081d0692:
          iVar6 = asn1_const_Finish(&local_78);
          if (iVar6 == 0) goto LAB_081d060a;
          a_00->length = iVar5;
          if (a_00->data != (uchar *)0x0) {
            CRYPTO_free(a_00->data);
          }
          a_00->data = (uchar *)local_90.data;
          puVar4 = local_78.p;
          if (local_d0 != (ASN1_STRING *)0x0) {
            ASN1_STRING_free(local_d0);
            puVar4 = local_78.p;
          }
          goto LAB_081d090c;
        }
        if (local_b0 == 0) {
          if (a_00->data == (uchar *)0x0) {
            __dest = (uchar *)0x0;
            puVar4 = local_b4;
          }
          else {
            __dest = (uchar *)0x0;
            CRYPTO_free(a_00->data);
            puVar4 = local_b4;
          }
        }
        else {
          if ((a_00->length < (int)local_b0) || (__dest = a_00->data, __dest == (uchar *)0x0)) {
            __dest = (uchar *)CRYPTO_malloc(local_b0 + 1,"a_bytes.c",0xe9);
            if (__dest == (uchar *)0x0) {
              iVar5 = 0x41;
              goto LAB_081d0429;
            }
            if (a_00->data != (uchar *)0x0) {
              CRYPTO_free(a_00->data);
            }
          }
          memcpy(__dest,local_b4,local_b0);
          __dest[local_b0] = '\0';
          puVar4 = local_b4 + local_b0;
        }
        a_00->length = local_b0;
        a_00->data = __dest;
        a_00->type = Ptag;
LAB_081d090c:
        if (a != (ASN1_STRING **)0x0) {
          *a = a_00;
        }
        *pp = puVar4;
        goto LAB_081d0444;
      }
      goto LAB_081d0429;
    }
    iVar5 = 0x66;
    if (a_00 != *a) goto LAB_081d0432;
    iVar5 = 0x66;
    goto LAB_081d0478;
  }
  a_00 = ASN1_STRING_new();
  if (a_00 != (ASN1_STRING *)0x0) {
    local_b4 = *pp;
    uVar1 = ASN1_get_object(&local_b4,(long *)&local_b0,&local_ac,&local_a8,length);
    if ((uVar1 & 0x80) == 0) goto LAB_081d0413;
    iVar5 = 0x66;
    goto LAB_081d0429;
  }
  goto LAB_081d0495;
LAB_081d0878:
  iVar2 = asn1_const_Finish(&local_4c);
  if (iVar2 == 0) {
LAB_081d0a38:
    if (local_94 != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(local_94);
    }
    if ((uchar *)local_84.data != (uchar *)0x0) {
      CRYPTO_free(local_84.data);
    }
    local_78.error = local_4c.error;
LAB_081d05f8:
    if (a_01 != local_d0) {
      ASN1_STRING_free(a_01);
    }
LAB_081d060a:
    if (local_d0 == (ASN1_STRING *)0x0) goto LAB_081d0621;
    goto LAB_081d0612;
  }
  a_01->length = iVar6;
  if (a_01->data != (uchar *)0x0) {
    CRYPTO_free(a_01->data);
  }
  a_01->data = (uchar *)local_84.data;
  if (local_94 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_94);
  }
  sVar3 = a_01->length;
  local_78.p = local_4c.p;
LAB_081d096a:
  iVar6 = BUF_MEM_grow_clean(&local_90,sVar3 + iVar5);
  local_d0 = a_01;
  if (iVar6 == 0) goto LAB_081d0a70;
  memcpy(local_90.data + iVar5,a_01->data,a_01->length);
  if ((local_78.inf & 1U) == 0) {
    local_78.slen = local_78.slen - ((int)local_78.p - (int)local_78.q);
  }
  iVar5 = iVar5 + a_01->length;
  goto LAB_081d0578;
LAB_081d0a70:
  local_78.error = 7;
LAB_081d0612:
  ASN1_STRING_free(local_d0);
LAB_081d0621:
  iVar5 = local_78.error;
  if ((uchar *)local_90.data != (uchar *)0x0) {
    CRYPTO_free(local_90.data);
    iVar5 = local_78.error;
  }
LAB_081d0429:
  if ((a == (ASN1_STRING **)0x0) || (*a != a_00)) {
LAB_081d0432:
    ASN1_STRING_free(a_00);
  }
  a_00 = (ASN1_STRING *)0x0;
  if (iVar5 == 0) goto LAB_081d0444;
LAB_081d0478:
  ERR_put_error(0xd,0x8f,iVar5,"a_bytes.c",0xaf);
LAB_081d0495:
  a_00 = (ASN1_STRING *)0x0;
LAB_081d0444:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a_00;
}

