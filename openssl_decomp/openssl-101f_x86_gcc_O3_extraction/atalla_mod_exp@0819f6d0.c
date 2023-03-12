
undefined4 __regparm3
atalla_mod_exp(BIGNUM *param_1_00,BIGNUM *param_2_00,BIGNUM *param_3,BIGNUM *param_1,BN_CTX *param_2
              )

{
  ulong *puVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar2;
  BIGNUM *pBVar3;
  int iVar4;
  size_t __n;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_GS_OFFSET;
  byte bVar7;
  undefined4 local_6c [3];
  ulong *local_60;
  size_t local_5c;
  ulong *local_50;
  size_t local_4c;
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (atalla_dso == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x1d0;
    iVar4 = 0x69;
  }
  else {
    BN_CTX_start(param_2);
    a = BN_CTX_get(param_2);
    a_00 = BN_CTX_get(param_2);
    a_01 = BN_CTX_get(param_2);
    a_02 = BN_CTX_get(param_2);
    if (a_02 == (BIGNUM *)0x0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x1db;
      iVar4 = 0x65;
    }
    else {
      iVar4 = param_1->top;
      if (a->dmax < iVar4) {
        pBVar3 = bn_expand2(a,iVar4);
        if (pBVar3 != (BIGNUM *)0x0) {
          iVar4 = param_1->top;
          goto LAB_0819f75f;
        }
LAB_0819f998:
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = ERR_get_next_error_library();
          iVar2 = 0x1e1;
          iVar4 = 0x66;
        }
        else {
          iVar2 = 0x1e1;
          iVar4 = 0x66;
        }
      }
      else {
LAB_0819f75f:
        if (a_00->dmax < iVar4) {
          pBVar3 = bn_expand2(a_00,iVar4);
          if (pBVar3 == (BIGNUM *)0x0) goto LAB_0819f998;
          iVar4 = param_1->top;
          if (a_01->dmax < iVar4) goto LAB_0819f923;
LAB_0819f779:
          if (a_02->dmax < iVar4) {
LAB_0819f980:
            pBVar3 = bn_expand2(a_02,iVar4);
            if (pBVar3 == (BIGNUM *)0x0) goto LAB_0819f998;
          }
        }
        else {
          if (iVar4 <= a_01->dmax) goto LAB_0819f779;
LAB_0819f923:
          pBVar3 = bn_expand2(a_01,iVar4);
          if (pBVar3 == (BIGNUM *)0x0) goto LAB_0819f998;
          iVar4 = param_1->top;
          if (a_02->dmax < iVar4) goto LAB_0819f980;
        }
        puVar6 = local_6c;
        for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
        }
        iVar2 = BN_num_bits(param_1);
        iVar4 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar4 = iVar2 + 7;
        }
        __n = iVar4 >> 3;
        memset(a_00->d,0,__n);
        memset(a->d,0,__n);
        puVar1 = a_00->d;
        iVar2 = BN_num_bits(param_3);
        iVar4 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar4 = iVar2 + 0xe;
        }
        BN_bn2bin(param_3,(uchar *)((int)puVar1 + (__n - (iVar4 >> 3))));
        puVar1 = a->d;
        iVar2 = BN_num_bits(param_1);
        iVar4 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar4 = iVar2 + 0xe;
        }
        BN_bn2bin(param_1,(uchar *)((int)puVar1 + (__n - (iVar4 >> 3))));
        local_50 = a_00->d;
        local_60 = a->d;
        local_5c = __n;
        local_4c = __n;
        memset(a_01->d,0,__n);
        memset(a_02->d,0,__n);
        puVar1 = a_01->d;
        iVar2 = BN_num_bits(param_2_00);
        iVar4 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar4 = iVar2 + 0xe;
        }
        BN_bn2bin(param_2_00,(uchar *)((int)puVar1 + (__n - (iVar4 >> 3))));
        iVar4 = (*p_Atalla_RSAPrivateKeyOpFn)(local_6c,a_02->d,a_01->d,local_5c);
        if (iVar4 == 0) {
          uVar5 = 1;
          BN_bin2bn((uchar *)a_02->d,__n,param_1_00);
          goto LAB_0819f8ce;
        }
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = ERR_get_next_error_library();
        }
        iVar2 = 0x1f8;
        iVar4 = 0x6a;
      }
    }
  }
  uVar5 = 0;
  ERR_put_error(ATALLA_lib_error_code,0x67,iVar4,"e_atalla.c",iVar2);
LAB_0819f8ce:
  BN_CTX_end(param_2);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

