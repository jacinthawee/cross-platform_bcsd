
ASN1_STRING * __regparm3
int_d2i_ASN1_bytes(ASN1_STRING **param_1_00,uchar **param_2_00,int param_3_00,int param_1,
                  int param_2,int param_3,int *param_4)

{
  uint uVar1;
  ASN1_STRING *a;
  ASN1_STRING *a_00;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  uchar *__dest;
  int iVar6;
  int omax;
  int in_GS_OFFSET;
  ASN1_STRING *local_d4;
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
  if (0x14 < param_3) {
    *param_4 = 0xc5;
    a = (ASN1_STRING *)0x0;
    goto LAB_081cf97d;
  }
  if (((param_1_00 != (ASN1_STRING **)0x0) && (a = *param_1_00, a != (ASN1_STRING *)0x0)) ||
     (a = ASN1_STRING_new(), a != (ASN1_STRING *)0x0)) {
    local_b4 = *param_2_00;
    uVar1 = ASN1_get_object(&local_b4,(long *)&local_b0,&local_ac,&local_a8,param_3_00);
    if ((uchar *)(uVar1 & 0x80) == (uchar *)0x0) {
      if (local_ac == param_1) {
        if ((uVar1 & 0x20) != 0) {
          local_78.error = 0;
          local_90.length = 0;
          local_78.p = local_b4;
          local_78.max = (uchar *)(uVar1 & 0x80);
          if (param_3_00 != 0) {
            local_78.max = local_b4 + param_3_00;
          }
          local_90.max = 0;
          local_90.data = (char *)0x0;
          local_78.slen = local_b0;
          local_d4 = (ASN1_STRING *)0x0;
          local_78.tag = param_1;
          local_78.xclass = param_2;
          iVar6 = 0;
          local_78.inf = uVar1;
          local_78.pp = param_2_00;
LAB_081cfa50:
          if ((local_78.inf & 1U) == 0) {
            if (local_78.slen < 1) goto LAB_081cfb82;
LAB_081cfa64:
            iVar4 = local_78.xclass;
            iVar3 = local_78.tag;
            local_78.q = local_78.p;
            omax = (int)local_78.max - (int)local_78.p;
            if (param_3 == 0x14) {
              local_78.error = 0xc5;
              goto LAB_081cfaf0;
            }
            a_00 = local_d4;
            if ((local_d4 != (ASN1_STRING *)0x0) ||
               (a_00 = ASN1_STRING_new(), a_00 != (ASN1_STRING *)0x0)) {
              local_a4 = local_78.p;
              uVar1 = ASN1_get_object(&local_a4,(long *)&local_a0,&local_9c,&local_98,omax);
              if ((uchar *)(uVar1 & 0x80) == (uchar *)0x0) {
                if (iVar3 != local_9c) {
                  local_78.error = 0xa8;
                  goto LAB_081cfade;
                }
                if ((uVar1 & 0x20) != 0) {
                  local_4c.pp = (uchar **)&local_78;
                  local_4c.tag = iVar3;
                  local_4c.error = 0;
                  local_4c.xclass = iVar4;
                  local_94 = (ASN1_STRING *)0x0;
                  local_84.length = 0;
                  local_4c.p = local_a4;
                  local_84.max = 0;
                  local_84.data = (char *)0x0;
                  local_4c.slen = local_a0;
                  local_4c.max = (uchar *)(uVar1 & 0x80);
                  if (omax != 0) {
                    local_4c.max = local_a4 + omax;
                  }
                  iVar3 = 0;
                  local_4c.inf = uVar1;
                  do {
                    if ((local_4c.inf & 1U) == 0) {
                      if (local_4c.slen < 1) goto LAB_081cfe9a;
                    }
                    else {
                      local_4c.eos = ASN1_const_check_infinite_end
                                               (&local_4c.p,(int)local_4c.max - (int)local_4c.p);
                      if (local_4c.eos != 0) goto LAB_081cfe9a;
                    }
                    local_4c.q = local_4c.p;
                    iVar4 = int_d2i_ASN1_bytes(local_4c.tag,local_4c.xclass,param_3 + 2,
                                               &local_4c.error);
                    if (iVar4 == 0) goto LAB_081cff68;
                    iVar4 = BUF_MEM_grow_clean(&local_84,local_94->length + iVar3);
                    if (iVar4 == 0) {
                      local_4c.error = 7;
                      goto LAB_081cff68;
                    }
                    memcpy(local_84.data + iVar3,local_94->data,local_94->length);
                    if ((local_4c.inf & 1U) == 0) {
                      local_4c.slen = local_4c.slen - ((int)local_4c.p - (int)local_4c.q);
                    }
                    iVar3 = iVar3 + local_94->length;
                  } while( true );
                }
                if (local_a0 == 0) {
                  if (a_00->data == (uchar *)0x0) {
                    puVar5 = (uchar *)0x0;
                    local_78.p = local_a4;
                  }
                  else {
                    puVar5 = (uchar *)0x0;
                    CRYPTO_free(a_00->data);
                    local_78.p = local_a4;
                  }
                }
                else {
                  if ((a_00->length < (int)local_a0) ||
                     (puVar5 = a_00->data, puVar5 == (uchar *)0x0)) {
                    puVar5 = (uchar *)CRYPTO_malloc(local_a0 + 1,"a_bytes.c",0xe9);
                    if (puVar5 == (uchar *)0x0) {
                      local_78.error = 0x41;
                      goto LAB_081cfade;
                    }
                    if (a_00->data != (uchar *)0x0) {
                      CRYPTO_free(a_00->data);
                    }
                  }
                  memcpy(puVar5,local_a4,local_a0);
                  puVar5[local_a0] = '\0';
                  local_78.p = local_a4 + local_a0;
                }
                a_00->length = local_a0;
                a_00->data = puVar5;
                a_00->type = iVar3;
                sVar2 = local_a0;
                goto LAB_081cfc5a;
              }
              local_78.error = 0x66;
              goto LAB_081cfade;
            }
            goto LAB_081cfb07;
          }
          local_78.eos = ASN1_const_check_infinite_end
                                   (&local_78.p,(int)local_78.max - (int)local_78.p);
          if (local_78.eos == 0) goto LAB_081cfa64;
LAB_081cfb82:
          iVar3 = asn1_const_Finish(&local_78);
          if (iVar3 == 0) goto LAB_081cfaf0;
          a->length = iVar6;
          if (a->data != (uchar *)0x0) {
            CRYPTO_free(a->data);
          }
          a->data = (uchar *)local_90.data;
          puVar5 = local_78.p;
          if (local_d4 != (ASN1_STRING *)0x0) {
            ASN1_STRING_free(local_d4);
            puVar5 = local_78.p;
          }
          goto LAB_081cfd06;
        }
        if (local_b0 == 0) {
          if (a->data == (uchar *)0x0) {
            __dest = (uchar *)0x0;
            puVar5 = local_b4;
          }
          else {
            __dest = (uchar *)0x0;
            CRYPTO_free(a->data);
            puVar5 = local_b4;
          }
        }
        else {
          if ((a->length < (int)local_b0) || (__dest = a->data, __dest == (uchar *)0x0)) {
            __dest = (uchar *)CRYPTO_malloc(local_b0 + 1,"a_bytes.c",0xe9);
            if (__dest == (uchar *)0x0) {
              *param_4 = 0x41;
              goto LAB_081cf967;
            }
            if (a->data != (uchar *)0x0) {
              CRYPTO_free(a->data);
            }
          }
          memcpy(__dest,local_b4,local_b0);
          __dest[local_b0] = '\0';
          puVar5 = local_b4 + local_b0;
        }
        a->length = local_b0;
        a->data = __dest;
        a->type = local_ac;
LAB_081cfd06:
        if (param_1_00 != (ASN1_STRING **)0x0) {
          *param_1_00 = a;
        }
        *param_2_00 = puVar5;
        goto LAB_081cf97d;
      }
      *param_4 = 0xa8;
    }
    else {
      *param_4 = 0x66;
    }
    goto LAB_081cf967;
  }
  goto LAB_081cf97b;
LAB_081cfe9a:
  iVar4 = asn1_const_Finish(&local_4c);
  if (iVar4 == 0) {
LAB_081cff68:
    if (local_94 != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(local_94);
    }
    if ((uchar *)local_84.data != (uchar *)0x0) {
      CRYPTO_free(local_84.data);
    }
    local_78.error = local_4c.error;
LAB_081cfade:
    if (a_00 != local_d4) {
      ASN1_STRING_free(a_00);
    }
LAB_081cfaf0:
    if (local_d4 == (ASN1_STRING *)0x0) goto LAB_081cfb07;
    goto LAB_081cfaf8;
  }
  a_00->length = iVar3;
  if (a_00->data != (uchar *)0x0) {
    CRYPTO_free(a_00->data);
  }
  a_00->data = (uchar *)local_84.data;
  if (local_94 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_94);
  }
  sVar2 = a_00->length;
  local_78.p = local_4c.p;
LAB_081cfc5a:
  iVar3 = BUF_MEM_grow_clean(&local_90,sVar2 + iVar6);
  local_d4 = a_00;
  if (iVar3 == 0) goto LAB_081cffa0;
  memcpy(local_90.data + iVar6,a_00->data,a_00->length);
  if ((local_78.inf & 1U) == 0) {
    local_78.slen = local_78.slen - ((int)local_78.p - (int)local_78.q);
  }
  iVar6 = iVar6 + a_00->length;
  goto LAB_081cfa50;
LAB_081cffa0:
  local_78.error = 7;
LAB_081cfaf8:
  ASN1_STRING_free(local_d4);
LAB_081cfb07:
  if ((uchar *)local_90.data != (uchar *)0x0) {
    CRYPTO_free(local_90.data);
  }
  *param_4 = local_78.error;
LAB_081cf967:
  if ((param_1_00 == (ASN1_STRING **)0x0) || (a != *param_1_00)) {
    ASN1_STRING_free(a);
  }
LAB_081cf97b:
  a = (ASN1_STRING *)0x0;
LAB_081cf97d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a;
}

