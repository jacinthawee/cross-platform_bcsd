
undefined4 __regparm3
asn1_template_ex_d2i
          (ASN1_VALUE **param_1_00,uchar **param_2_00,int param_3_00,ASN1_TEMPLATE *param_1,
          char param_2,char *param_3)

{
  uint uVar1;
  uchar *puVar2;
  undefined4 uVar3;
  uchar *puVar4;
  int in_GS_OFFSET;
  int iVar5;
  int iVar6;
  char *local_58;
  uint local_54;
  int local_30;
  uint local_2c;
  int local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1_00 == (ASN1_VALUE **)0x0) {
    uVar3 = 0;
    goto LAB_08149cc7;
  }
  uVar1 = param_1->flags;
  puVar2 = *param_2_00;
  if ((uVar1 & 0x10) == 0) {
    uVar3 = asn1_template_noexp_d2i(param_1,(int)param_2,param_3);
    goto LAB_08149cc7;
  }
  iVar6 = param_1->tag;
  local_24 = puVar2;
  if (param_3 == (char *)0x0) {
    local_54 = ASN1_get_object(&local_24,&local_28,&local_30,(int *)&local_2c,param_3_00);
    if ((local_54 & 0x80) != 0) {
      ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
      goto LAB_08149c85;
    }
LAB_08149c3f:
    puVar4 = local_24;
    if (-1 < iVar6) {
      if ((iVar6 != local_30) || ((uVar1 & 0xc0) != local_2c)) {
        if (param_2 != '\0') {
          uVar3 = 0xffffffff;
          goto LAB_08149cc7;
        }
        if (param_3 != (char *)0x0) {
          *param_3 = '\0';
        }
        ERR_put_error(0xd,0x68,0xa8,"tasn_dec.c",0x4af);
        goto LAB_08149c85;
      }
      if (param_3 != (char *)0x0) {
        *param_3 = '\0';
      }
    }
    iVar6 = local_28;
    if ((local_54 & 1) != 0) {
      iVar6 = param_3_00 - ((int)local_24 - (int)puVar2);
    }
    if ((local_54 & 0x20) != 0) {
      iVar5 = asn1_template_noexp_d2i(param_1,0,param_3);
      if (iVar5 != 0) {
        if ((local_54 & 1) == 0) {
          if (iVar6 != 0) {
            ERR_put_error(0xd,0x84,0x77,"tasn_dec.c",0x241);
            goto LAB_08149ea2;
          }
        }
        else {
          if (((iVar6 < 2) || (*puVar4 != '\0')) || (puVar4[1] != '\0')) {
            ERR_put_error(0xd,0x84,0x89,"tasn_dec.c",0x238);
LAB_08149ea2:
            ASN1_template_free(param_1_00,param_1);
            uVar3 = 0;
            goto LAB_08149cc7;
          }
          puVar4 = puVar4 + 2;
        }
        *param_2_00 = puVar4;
        uVar3 = 1;
        goto LAB_08149cc7;
      }
      iVar6 = 0x230;
      goto LAB_08149c8d;
    }
    iVar6 = 0x22a;
    iVar5 = 0x78;
  }
  else {
    if (*param_3 == '\0') {
      local_54 = ASN1_get_object(&local_24,&local_28,&local_30,(int *)&local_2c,param_3_00);
      *(uint *)(param_3 + 4) = local_54;
      *param_3 = '\x01';
      *(int *)(param_3 + 0x14) = (int)local_24 - (int)puVar2;
      *(int *)(param_3 + 8) = local_28;
      *(uint *)(param_3 + 0x10) = local_2c;
      *(int *)(param_3 + 0xc) = local_30;
      if (((local_54 & 0x81) != 0) || (local_28 + ((int)local_24 - (int)puVar2) <= param_3_00))
      goto LAB_08149c34;
      local_58 = param_3;
      iVar5 = 0x49b;
      iVar6 = 0x9b;
    }
    else {
      local_54 = *(uint *)(param_3 + 4);
      local_28 = *(int *)(param_3 + 8);
      local_2c = *(uint *)(param_3 + 0x10);
      local_30 = *(int *)(param_3 + 0xc);
      local_24 = puVar2 + *(int *)(param_3 + 0x14);
LAB_08149c34:
      if ((local_54 & 0x80) == 0) goto LAB_08149c3f;
      iVar5 = 0x4a3;
      iVar6 = 0x66;
      local_58 = param_3;
    }
    ERR_put_error(0xd,0x68,iVar6,"tasn_dec.c",iVar5);
    *local_58 = '\0';
LAB_08149c85:
    iVar6 = 0x224;
LAB_08149c8d:
    iVar5 = 0x3a;
  }
  ERR_put_error(0xd,0x84,iVar5,"tasn_dec.c",iVar6);
  uVar3 = 0;
LAB_08149cc7:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

