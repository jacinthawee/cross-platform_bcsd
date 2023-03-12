
undefined4
asn1_collect_constprop_0(BUF_MEM *param_1,uchar **param_2,uchar *param_3,uint param_4,int param_5)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  uchar *__n;
  size_t sVar4;
  uchar *local_3c;
  int iStack_38;
  int iStack_34;
  uchar *puStack_30;
  uchar *local_2c [2];
  
  param_4 = param_4 & 1;
  local_3c = *param_2;
  uVar3 = param_4 ^ 1;
  if (param_1 != (BUF_MEM *)0x0) {
    uVar3 = 0;
  }
  if (uVar3 != 0) {
    *param_2 = local_3c + (int)param_3;
    return 1;
  }
  if (0 < (int)param_3) {
    do {
      puVar1 = local_3c;
      if (((param_3 != (uchar *)0x1) && (*local_3c == '\0')) && (local_3c[1] == '\0')) {
        local_3c = local_3c + 2;
        if (param_4 == 0) {
          ERR_put_error(0xd,0x6a,0x9f,"tasn_dec.c",0x49c);
          return 0;
        }
        goto LAB_000bd436;
      }
      local_2c[0] = local_3c;
      uVar3 = ASN1_get_object(local_2c,(long *)&puStack_30,&iStack_38,&iStack_34,(long)param_3);
      if ((uVar3 & 0x80) != 0) {
        ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x51a);
        ERR_put_error(0xd,0x6a,0x3a,"tasn_dec.c",0x4a6);
        return 0;
      }
      local_3c = local_2c[0];
      __n = puStack_30;
      if ((int)(uVar3 << 0x1f) < 0) {
        __n = puVar1 + ((int)param_3 - (int)local_2c[0]);
      }
      if ((int)(uVar3 << 0x1a) < 0) {
        if (4 < param_5) {
          ERR_put_error(0xd,0x6a,0xc5,"tasn_dec.c",0x4b0);
          return 0;
        }
        iVar2 = asn1_collect_constprop_0(param_1,&local_3c,__n,uVar3 & 1,param_5 + 1);
        if (iVar2 == 0) {
          return 0;
        }
      }
      else if (__n != (uchar *)0x0) {
        if (param_1 != (BUF_MEM *)0x0) {
          sVar4 = param_1->length;
          iVar2 = BUF_MEM_grow_clean(param_1,(size_t)(__n + sVar4));
          if (iVar2 == 0) {
            ERR_put_error(0xd,0x8c,0x41,"tasn_dec.c",0x4cc);
            return 0;
          }
          memcpy(param_1->data + sVar4,local_3c,(size_t)__n);
        }
        local_3c = local_3c + (int)__n;
      }
      param_3 = puVar1 + ((int)param_3 - (int)local_3c);
    } while (0 < (int)param_3);
  }
  if (param_4 != 0) {
    ERR_put_error(0xd,0x6a,0x89,"tasn_dec.c",0x4bd);
    return 0;
  }
LAB_000bd436:
  *param_2 = local_3c;
  return 1;
}

