
/* WARNING: Could not reconcile some variable overlaps */

int __regparm3
asn1_d2i_ex_primitive
          (ASN1_VALUE **param_1_00,uchar **param_2_00,int param_3_00,ASN1_ITEM *param_1,uint param_2
          ,int param_3,char param_4,char *param_5)

{
  uint uVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  int in_GS_OFFSET;
  int iVar5;
  int iVar6;
  uchar *local_58;
  char local_41;
  uint local_40;
  uchar *local_3c;
  uint local_38;
  int local_34;
  uchar *local_30;
  BUF_MEM local_2c;
  int local_20;
  
  local_41 = '\0';
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1_00 == (ASN1_VALUE **)0x0) {
    iVar6 = 0x2d4;
    iVar5 = 0x7d;
    goto LAB_08148a4e;
  }
  if (param_1->itype == '\x05') {
    local_40 = param_2;
    if (param_2 != 0xfffffffc) {
LAB_08148af5:
      param_3 = 0;
      param_2 = local_40;
      goto LAB_081489ae;
    }
    param_2 = 0xffffffff;
LAB_08148b38:
    if (param_4 != '\0') {
      ERR_put_error(0xd,0x6c,0x7e,"tasn_dec.c",0x2e7);
      goto LAB_08148a5a;
    }
    local_3c = *param_2_00;
    iVar5 = asn1_check_tlen_constprop_1(0,0,&local_3c,param_3_00,0,param_5);
    if (iVar5 != 0) {
      if ((char)local_2c.length != '\0') {
        local_40 = 0xfffffffd;
      }
      goto LAB_081489a3;
    }
    iVar6 = 0x2ee;
LAB_08148a47:
    iVar5 = 0x3a;
LAB_08148a4e:
    ERR_put_error(0xd,0x6c,iVar5,"tasn_dec.c",iVar6);
  }
  else {
    local_40 = param_1->utype;
    if (local_40 != 0xfffffffc) {
LAB_081489a3:
      if (param_2 == 0xffffffff) goto LAB_08148af5;
LAB_081489ae:
      puVar2 = *param_2_00;
      local_3c = puVar2;
      local_2c.length = (size_t)puVar2;
      if (param_5 != (char *)0x0) {
        if (*param_5 == '\0') {
          uVar1 = ASN1_get_object((uchar **)&local_2c,(long *)&local_30,(int *)&local_38,&local_34,
                                  param_3_00);
          *(uint *)(param_5 + 4) = uVar1;
          *param_5 = '\x01';
          *(int *)(param_5 + 0x10) = local_34;
          *(uchar **)(param_5 + 8) = local_30;
          *(uint *)(param_5 + 0xc) = local_38;
          *(size_t *)(param_5 + 0x14) = local_2c.length - (int)puVar2;
          if (((uVar1 & 0x81) != 0) ||
             ((int)(local_30 + (local_2c.length - (int)puVar2)) <= param_3_00)) goto LAB_081489ed;
          iVar6 = 0x49b;
          iVar5 = 0x9b;
        }
        else {
          local_30 = *(uchar **)(param_5 + 8);
          uVar1 = *(uint *)(param_5 + 4);
          local_34 = *(int *)(param_5 + 0x10);
          local_38 = *(uint *)(param_5 + 0xc);
          local_2c.length = (size_t)(puVar2 + *(int *)(param_5 + 0x14));
LAB_081489ed:
          if ((uVar1 & 0x80) == 0) goto LAB_081489f5;
          iVar6 = 0x4a3;
          iVar5 = 0x66;
        }
        ERR_put_error(0xd,0x68,iVar5,"tasn_dec.c",iVar6);
        *param_5 = '\0';
LAB_08148a3f:
        iVar6 = 0x2fd;
        goto LAB_08148a47;
      }
      uVar1 = ASN1_get_object((uchar **)&local_2c,(long *)&local_30,(int *)&local_38,&local_34,
                              param_3_00);
      if ((uVar1 & 0x80) != 0) {
        ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
        goto LAB_08148a3f;
      }
LAB_081489f5:
      if (-1 < (int)param_2) {
        if ((param_2 != local_38) || (param_3 != local_34)) {
          if (param_4 != '\0') {
            iVar5 = -1;
            goto LAB_08148a5c;
          }
          if (param_5 != (char *)0x0) {
            *param_5 = '\0';
          }
          ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x4af);
          goto LAB_08148a3f;
        }
        if (param_5 != (char *)0x0) {
          *param_5 = '\0';
        }
      }
      if ((uVar1 & 1) == 0) {
        local_58 = local_30;
      }
      else {
        local_58 = (uchar *)(param_3_00 - (local_2c.length - (int)puVar2));
      }
      local_3c = (uchar *)local_2c.length;
      if ((local_40 - 0x10 < 2) || (local_40 == 0xfffffffd)) {
        if (local_40 == 0xfffffffd) {
          if (param_5 != (char *)0x0) {
            *param_5 = '\0';
          }
        }
        else if ((uVar1 & 0x20) == 0) {
          iVar6 = 0x30f;
          iVar5 = 0x9c;
          goto LAB_08148a4e;
        }
        puVar2 = *param_2_00;
        if ((uVar1 & 1) == 0) {
          local_2c.data = (char *)0x0;
          local_3c = (uchar *)(local_2c.length + (int)local_58);
          local_58 = local_58 + (local_2c.length - (int)puVar2);
          goto LAB_08148c80;
        }
        iVar5 = 1;
        local_3c = (uchar *)local_2c.length;
        puVar3 = (uchar *)local_2c.length;
        while (0 < (int)local_58) {
          if (((local_58 == (uchar *)0x1) || (*puVar3 != '\0')) || (puVar3[1] != '\0')) {
            local_2c.length = (size_t)puVar3;
            uVar1 = ASN1_get_object((uchar **)&local_2c,(long *)&local_30,(int *)&local_38,&local_34
                                    ,(long)local_58);
            if ((uVar1 & 0x80) != 0) {
              ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
              ERR_put_error(0xd,0xbe,0x3a,"tasn_dec.c",0x3fc);
              goto LAB_08148d20;
            }
            puVar4 = local_30;
            if ((uVar1 & 1) != 0) {
              puVar4 = local_58 + -(local_2c.length - (int)puVar3);
            }
            if ((uVar1 & 1) == 0) {
              puVar4 = (uchar *)(local_2c.length + (int)puVar4);
            }
            else {
              iVar5 = iVar5 + 1;
              puVar4 = (uchar *)local_2c.length;
            }
            local_58 = local_58 + -((int)puVar4 - (int)puVar3);
            puVar3 = puVar4;
          }
          else {
            puVar3 = puVar3 + 2;
            iVar5 = iVar5 + -1;
            if (iVar5 == 0) {
              local_58 = puVar3 + -(int)puVar2;
              local_3c = puVar3;
              goto LAB_08148c80;
            }
            local_58 = local_58 + -2;
          }
        }
        ERR_put_error(0xd,0xbe,0x89,"tasn_dec.c",0x406);
        iVar5 = 0;
LAB_08148cae:
        if (local_41 == '\0') goto LAB_08148a5c;
LAB_08148cbb:
        if ((uchar *)local_2c.data != (uchar *)0x0) {
          CRYPTO_free(local_2c.data);
        }
        goto LAB_08148a5c;
      }
      if ((uVar1 & 0x20) == 0) {
        puVar2 = (uchar *)local_2c.length;
        local_3c = local_58 + local_2c.length;
LAB_08148c80:
        iVar5 = asn1_ex_c2i(param_1_00,puVar2,(int)local_58,local_40,&local_41,param_1);
        if (iVar5 == 0) {
LAB_08148d20:
          iVar5 = 0;
        }
        else {
          iVar5 = 1;
          *param_2_00 = local_3c;
        }
        goto LAB_08148cae;
      }
      if ((1 < (local_40 & 0xfffffffb) - 1) && (local_40 != 10)) {
        local_2c.length = 0;
        local_2c.max = 0;
        local_2c.data = (char *)0x0;
        iVar5 = asn1_collect_constprop_0((byte)uVar1 & 1,0);
        local_58 = (uchar *)local_2c.length;
        if (iVar5 != 0) {
          iVar5 = BUF_MEM_grow_clean(&local_2c,(size_t)(local_2c.length + 1));
          if (iVar5 == 0) {
            ERR_put_error(0xd,0x6c,0x41,"tasn_dec.c",0x335);
            goto LAB_08148a5c;
          }
          local_2c.data[(int)local_58] = '\0';
          local_41 = '\x01';
          puVar2 = (uchar *)local_2c.data;
          goto LAB_08148c80;
        }
        local_41 = '\x01';
        iVar5 = 0;
        goto LAB_08148cbb;
      }
      iVar6 = 0x322;
      iVar5 = 0xda;
      goto LAB_08148a4e;
    }
    if ((int)param_2 < 0) goto LAB_08148b38;
    ERR_put_error(0xd,0x6c,0x7f,"tasn_dec.c",0x2e2);
  }
LAB_08148a5a:
  iVar5 = 0;
LAB_08148a5c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

