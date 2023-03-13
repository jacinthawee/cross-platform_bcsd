
uint __regparm3
asn1_collect_constprop_0
          (BUF_MEM *param_1_00,uchar **param_2_00,int param_3,byte param_1,int param_2)

{
  size_t sVar1;
  uchar *__src;
  uint uVar2;
  uint uVar3;
  int iVar4;
  size_t __n;
  uchar *puVar5;
  int in_GS_OFFSET;
  int line;
  int local_30;
  int local_2c;
  size_t local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  puVar5 = *param_2_00;
  param_1 = param_1 & 1;
  if ((param_1_00 == (BUF_MEM *)0x0) && (param_1 == 0)) {
    uVar2 = 1;
    *param_2_00 = puVar5 + param_3;
  }
  else {
    if (0 < param_3) {
      do {
        if (((param_3 != 1) && (*puVar5 == '\0')) && (puVar5[1] == '\0')) {
          puVar5 = puVar5 + 2;
          if (param_1 != 0) goto LAB_08148568;
          line = 0x435;
          iVar4 = 0x9f;
          goto LAB_081484f7;
        }
        local_24 = puVar5;
        uVar3 = ASN1_get_object(&local_24,(long *)&local_28,&local_30,&local_2c,param_3);
        __src = local_24;
        uVar2 = uVar3 & 0x80;
        if (uVar2 != 0) {
          ERR_put_error(0xd,0x68,0x66,"tasn_dec.c",0x4a3);
          line = 0x43e;
          iVar4 = 0x3a;
          goto LAB_081484f7;
        }
        __n = local_28;
        if ((uVar3 & 1) != 0) {
          __n = param_3 - ((int)local_24 - (int)puVar5);
        }
        if ((uVar3 & 0x20) == 0) {
          if (__n == 0) goto LAB_081483ce;
          if (param_1_00 != (BUF_MEM *)0x0) {
            sVar1 = param_1_00->length;
            uVar2 = BUF_MEM_grow_clean(param_1_00,sVar1 + __n);
            if (uVar2 == 0) {
              ERR_put_error(0xd,0x8c,0x41,"tasn_dec.c",0x45c);
              goto LAB_08148505;
            }
            memcpy(param_1_00->data + sVar1,__src,__n);
          }
          iVar4 = (int)(__src + __n) - (int)puVar5;
          puVar5 = __src + __n;
        }
        else {
          if (4 < param_2) {
            ERR_put_error(0xd,0x6a,0xc5,"tasn_dec.c",0x445);
            goto LAB_08148505;
          }
          uVar2 = asn1_collect_constprop_0(uVar3 & 1,param_2 + 1);
          if (uVar2 == 0) goto LAB_08148505;
LAB_081483ce:
          iVar4 = (int)__src - (int)puVar5;
          puVar5 = __src;
        }
        param_3 = param_3 - iVar4;
      } while (0 < param_3);
    }
    if (param_1 == 0) {
LAB_08148568:
      *param_2_00 = puVar5;
      uVar2 = 1;
    }
    else {
      line = 0x44f;
      iVar4 = 0x89;
LAB_081484f7:
      ERR_put_error(0xd,0x6a,iVar4,"tasn_dec.c",line);
      uVar2 = 0;
    }
  }
LAB_08148505:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

