
void cswift_dsa_verify(undefined4 param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  BN_CTX *ctx;
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  ulong *puVar3;
  int iVar4;
  BIGNUM *pBVar5;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  int *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  ulong *local_6c;
  undefined4 local_68;
  int local_64;
  ulong *local_60;
  int local_5c;
  ulong *local_58;
  int local_54;
  ulong *local_50;
  int local_4c;
  ulong *local_48;
  undefined auStack_3c [16];
  int local_2c;
  
  local_2c = __TMC_END__;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    local_84 = -1;
    goto LAB_000f239c;
  }
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_88);
  if (iVar1 == 0) {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    a_01 = BN_CTX_get(ctx);
    a_02 = BN_CTX_get(ctx);
    if (a_02 == (BIGNUM *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      local_84 = -1;
      ERR_put_error(CSWIFT_lib_error_code,0x66,0x66,"e_cswift.c",0x3b7);
      goto LAB_000f254c;
    }
    iVar1 = *(int *)(*(int *)(param_4 + 0xc) + 4);
    if (pBVar2->dmax < iVar1) {
      pBVar5 = bn_expand2(pBVar2,iVar1);
      if (pBVar5 != (BIGNUM *)0x0) {
        iVar1 = *(int *)(*(int *)(param_4 + 0x10) + 4);
        if (a->dmax < iVar1) goto LAB_000f25ca;
        goto LAB_000f23fe;
      }
LAB_000f2560:
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      local_84 = -1;
      ERR_put_error(CSWIFT_lib_error_code,0x66,0x67,"e_cswift.c",0x3c0);
    }
    else {
      iVar1 = *(int *)(*(int *)(param_4 + 0x10) + 4);
      if (a->dmax < iVar1) {
LAB_000f25ca:
        pBVar5 = bn_expand2(a,iVar1);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_000f2560;
      }
LAB_000f23fe:
      iVar1 = *(int *)(*(int *)(param_4 + 0x14) + 4);
      if ((a_00->dmax < iVar1) && (pBVar5 = bn_expand2(a_00,iVar1), pBVar5 == (BIGNUM *)0x0))
      goto LAB_000f2560;
      iVar1 = *(int *)(*(int *)(param_4 + 0x18) + 4);
      if (a_01->dmax < iVar1) {
        pBVar5 = bn_expand2(a_01,iVar1);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_000f2560;
        iVar1 = a_02->dmax;
      }
      else {
        iVar1 = a_02->dmax;
      }
      if ((iVar1 < 0x28) && (pBVar5 = bn_expand2(a_02,0x28), pBVar5 == (BIGNUM *)0x0))
      goto LAB_000f2560;
      local_68 = 3;
      local_64 = BN_bn2bin(*(BIGNUM **)(param_4 + 0xc),(uchar *)pBVar2->d);
      local_60 = pBVar2->d;
      local_5c = BN_bn2bin(*(BIGNUM **)(param_4 + 0x10),(uchar *)a->d);
      local_58 = a->d;
      local_54 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x14),(uchar *)a_00->d);
      local_50 = a_00->d;
      local_4c = BN_bn2bin(*(BIGNUM **)(param_4 + 0x18),(uchar *)a_01->d);
      local_48 = a_01->d;
      iVar1 = (*p_CSwift_AttachKeyParam)(local_88,&local_68);
      if (iVar1 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        local_84 = -1;
        ERR_put_error(CSWIFT_lib_error_code,0x66,0x65,"e_cswift.c",0x3d7);
      }
      else {
        if (iVar1 == 0) {
          puVar3 = a_02->d;
          local_70 = 0x28;
          local_78 = param_2;
          local_74 = param_1;
          local_6c = puVar3;
          memset(puVar3,0,0x28);
          pBVar2 = *param_3;
          iVar4 = BN_num_bits(pBVar2);
          iVar1 = iVar4 + 0xe;
          if (-1 < iVar4 + 7) {
            iVar1 = iVar4 + 7;
          }
          BN_bn2bin(pBVar2,(uchar *)((0x14 - (iVar1 >> 3)) + (int)puVar3));
          puVar3 = local_6c;
          pBVar2 = param_3[1];
          iVar4 = BN_num_bits(pBVar2);
          iVar1 = iVar4 + 0xe;
          if (-1 < iVar4 + 7) {
            iVar1 = iVar4 + 7;
          }
          BN_bn2bin(pBVar2,(uchar *)((0x28 - (iVar1 >> 3)) + (int)puVar3));
          local_7c = &local_84;
          local_80 = 4;
          iVar1 = (*p_CSwift_SimpleRequest)(local_88,4,&local_78,2,&local_80,1);
          if (iVar1 == 0) {
            if (local_84 != 0) {
              local_84 = 1;
            }
            goto LAB_000f254c;
          }
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          iVar4 = 0x3f2;
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          iVar4 = 0x3dc;
        }
        ERR_put_error(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",iVar4);
        local_84 = -1;
        __sprintf_chk(auStack_3c,1,0xd,&DAT_001695a8,iVar1);
        ERR_add_error_data(2,"CryptoSwift error number is ",auStack_3c);
      }
    }
LAB_000f254c:
    (*p_CSwift_ReleaseAccContext)(local_88);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    local_84 = -1;
    ERR_put_error(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x3aa);
  }
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_000f239c:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_84);
}

