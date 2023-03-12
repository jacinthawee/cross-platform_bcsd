
/* WARNING: Could not reconcile some variable overlaps */

int __regparm3
asn1_d2i_ex_primitive
          (ASN1_VALUE **param_1_00,uchar **param_2_00,int param_3_00,ASN1_ITEM *param_1,int param_2,
          int param_3,char param_4,char *param_5)

{
  uint uVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *omax;
  int in_GS_OFFSET;
  int iVar5;
  int iVar6;
  char local_41;
  int local_40;
  uchar *local_3c;
  int local_38;
  int local_34;
  uchar *local_30;
  BUF_MEM local_2c;
  int local_20;
  
  local_41 = '\0';
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1_00 == (ASN1_VALUE **)0x0) {
    iVar6 = 0x30c;
    iVar5 = 0x7d;
LAB_0814b420:
    ERR_put_error(0xd,0x6c,iVar5,"tasn_dec.c",iVar6);
  }
  else {
    if (param_1->itype == '\x05') {
      local_40 = param_2;
      if (param_2 != -4) {
LAB_0814b4cd:
        param_3 = 0;
        param_2 = local_40;
        goto LAB_0814b37f;
      }
      param_2 = -1;
LAB_0814b518:
      if (param_4 != '\0') {
        ERR_put_error(0xd,0x6c,0x7e,"tasn_dec.c",0x325);
        goto LAB_0814b42c;
      }
      local_3c = *param_2_00;
      iVar5 = asn1_check_tlen_constprop_1(0,0,&local_3c,param_3_00,0,param_5);
      if (iVar5 != 0) {
        if ((char)local_2c.length != '\0') {
          local_40 = -3;
        }
        goto LAB_0814b374;
      }
      iVar6 = 0x32e;
LAB_0814b419:
      iVar5 = 0x3a;
      goto LAB_0814b420;
    }
    local_40 = param_1->utype;
    if (local_40 != -4) {
LAB_0814b374:
      if (param_2 == -1) goto LAB_0814b4cd;
LAB_0814b37f:
      puVar2 = *param_2_00;
      local_3c = puVar2;
      local_2c.length = (size_t)puVar2;
      if (param_5 == (char *)0x0) {
        uVar1 = ASN1_get_object((uchar **)&local_2c,(long *)&local_30,&local_38,&local_34,param_3_00
                               );
        if ((uVar1 & 0x80) == 0) {
LAB_0814b3c7:
          if (-1 < param_2) {
            if ((param_2 != local_38) || (param_3 != local_34)) {
              if (param_4 != '\0') {
                iVar5 = -1;
                goto LAB_0814b42e;
              }
              if (param_5 != (char *)0x0) {
                *param_5 = '\0';
              }
              ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x527);
              goto LAB_0814b411;
            }
            if (param_5 != (char *)0x0) {
              *param_5 = '\0';
            }
          }
          omax = local_30;
          if ((uVar1 & 1) != 0) {
            omax = (uchar *)(param_3_00 - (local_2c.length - (int)puVar2));
          }
          local_3c = (uchar *)local_2c.length;
          if ((local_40 - 0x10U < 2) || (local_40 == -3)) {
            if (local_40 == -3) {
              if (param_5 != (char *)0x0) {
                *param_5 = '\0';
              }
            }
            else if ((uVar1 & 0x20) == 0) {
              iVar6 = 0x354;
              iVar5 = 0x9c;
              goto LAB_0814b420;
            }
            puVar2 = *param_2_00;
            if ((uVar1 & 1) == 0) {
              local_3c = (uchar *)(local_2c.length + (int)omax);
              local_2c.data = (char *)0x0;
              omax = omax + (local_2c.length - (int)puVar2);
              goto LAB_0814b5cb;
            }
            if (0 < (int)omax) {
              iVar5 = 1;
              puVar3 = (uchar *)local_2c.length;
              do {
                if (((omax == (uchar *)0x1) || (*puVar3 != '\0')) || (puVar3[1] != '\0')) {
                  local_2c.length = (size_t)puVar3;
                  uVar1 = ASN1_get_object((uchar **)&local_2c,(long *)&local_30,&local_38,&local_34,
                                          (long)omax);
                  if ((uVar1 & 0x80) != 0) {
                    ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
                    ERR_put_error(0xd,0xbe,0x3a,"tasn_dec.c",0x461);
                    goto LAB_0814b6b0;
                  }
                  puVar4 = local_30;
                  if ((uVar1 & 1) != 0) {
                    puVar4 = omax + -(local_2c.length - (int)puVar3);
                  }
                  if ((uVar1 & 1) == 0) {
                    puVar4 = (uchar *)(local_2c.length + (int)puVar4);
                  }
                  else {
                    iVar5 = iVar5 + 1;
                    puVar4 = (uchar *)local_2c.length;
                  }
                  omax = omax + -((int)puVar4 - (int)puVar3);
                }
                else {
                  puVar4 = puVar3 + 2;
                  iVar5 = iVar5 + -1;
                  if (iVar5 == 0) {
                    omax = puVar4 + -(int)puVar2;
                    local_3c = puVar4;
                    goto LAB_0814b5cb;
                  }
                  omax = omax + -2;
                }
                puVar3 = puVar4;
              } while (0 < (int)omax);
            }
            ERR_put_error(0xd,0xbe,0x89,"tasn_dec.c",0x46c);
            iVar5 = 0;
LAB_0814b5fa:
            if (local_41 == '\0') goto LAB_0814b42e;
          }
          else {
            if ((uVar1 & 0x20) == 0) {
              puVar2 = (uchar *)local_2c.length;
              local_3c = (uchar *)(local_2c.length + (int)omax);
LAB_0814b5cb:
              iVar5 = asn1_ex_c2i(param_1_00,puVar2,(int)omax,local_40,&local_41,param_1);
              if (iVar5 == 0) {
LAB_0814b6b0:
                iVar5 = 0;
              }
              else {
                iVar5 = 1;
                *param_2_00 = local_3c;
              }
              goto LAB_0814b5fa;
            }
            local_2c.length = 0;
            local_2c.max = 0;
            local_2c.data = (char *)0x0;
            iVar5 = asn1_collect_constprop_0((byte)uVar1 & 1,0);
            omax = (uchar *)local_2c.length;
            if (iVar5 != 0) {
              iVar5 = BUF_MEM_grow_clean(&local_2c,(size_t)(local_2c.length + 1));
              if (iVar5 == 0) {
                ERR_put_error(0xd,0x6c,0x41,"tasn_dec.c",0x37c);
                goto LAB_0814b42e;
              }
              local_2c.data[(int)omax] = '\0';
              local_41 = '\x01';
              puVar2 = (uchar *)local_2c.data;
              goto LAB_0814b5cb;
            }
            local_41 = '\x01';
            iVar5 = 0;
          }
          if ((uchar *)local_2c.data != (uchar *)0x0) {
            CRYPTO_free(local_2c.data);
          }
          goto LAB_0814b42e;
        }
        ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
      }
      else {
        if (*param_5 == '\0') {
          uVar1 = ASN1_get_object((uchar **)&local_2c,(long *)&local_30,&local_38,&local_34,
                                  param_3_00);
          *(uint *)(param_5 + 4) = uVar1;
          *param_5 = '\x01';
          *(int *)(param_5 + 0x10) = local_34;
          *(uchar **)(param_5 + 8) = local_30;
          *(int *)(param_5 + 0xc) = local_38;
          *(size_t *)(param_5 + 0x14) = local_2c.length - (int)puVar2;
          if (((uVar1 & 0x81) != 0) ||
             ((int)(local_30 + (local_2c.length - (int)puVar2)) <= param_3_00)) goto LAB_0814b3bf;
          iVar6 = 0x511;
          iVar5 = 0x9b;
        }
        else {
          local_30 = *(uchar **)(param_5 + 8);
          uVar1 = *(uint *)(param_5 + 4);
          local_34 = *(int *)(param_5 + 0x10);
          local_38 = *(int *)(param_5 + 0xc);
          local_2c.length = (size_t)(puVar2 + *(int *)(param_5 + 0x14));
LAB_0814b3bf:
          if ((uVar1 & 0x80) == 0) goto LAB_0814b3c7;
          iVar6 = 0x51a;
          iVar5 = 0x66;
        }
        ERR_put_error(0xd,0x68,iVar5,"tasn_dec.c",iVar6);
        *param_5 = '\0';
      }
LAB_0814b411:
      iVar6 = 0x33f;
      goto LAB_0814b419;
    }
    if (param_2 < 0) goto LAB_0814b518;
    ERR_put_error(0xd,0x6c,0x7f,"tasn_dec.c",799);
  }
LAB_0814b42c:
  iVar5 = 0;
LAB_0814b42e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

