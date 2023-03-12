
uint cswift_dsa_verify(undefined4 param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  ulong *puVar1;
  BN_CTX *ctx;
  int iVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  int iVar3;
  BIGNUM *pBVar4;
  uint uVar5;
  undefined4 *puVar6;
  int in_GS_OFFSET;
  byte bVar7;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  int *local_70;
  undefined4 local_6c;
  int local_68;
  ulong *local_64;
  int local_60;
  ulong *local_5c;
  int local_58;
  ulong *local_54;
  int local_50;
  ulong *local_4c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ulong *local_34;
  undefined local_2d [13];
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    uVar5 = 0xffffffff;
    goto LAB_081a2083;
  }
  iVar2 = (*p_CSwift_AcquireAccContext)(&local_7c);
  if (iVar2 == 0) {
    BN_CTX_start(ctx);
    a = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    a_01 = BN_CTX_get(ctx);
    a_02 = BN_CTX_get(ctx);
    a_03 = BN_CTX_get(ctx);
    if (a_03 == (BIGNUM *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar3 = 0x3b7;
      iVar2 = 0x66;
LAB_081a215c:
      uVar5 = 0xffffffff;
      ERR_put_error(CSWIFT_lib_error_code,0x66,iVar2,"e_cswift.c",iVar3);
    }
    else {
      iVar2 = *(int *)(*(int *)(param_4 + 0xc) + 4);
      if ((a->dmax < iVar2) && (pBVar4 = bn_expand2(a,iVar2), pBVar4 == (BIGNUM *)0x0)) {
LAB_081a218d:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x3c0;
        iVar2 = 0x67;
        goto LAB_081a215c;
      }
      iVar2 = *(int *)(*(int *)(param_4 + 0x10) + 4);
      if (a_00->dmax < iVar2) {
        pBVar4 = bn_expand2(a_00,iVar2);
        if (pBVar4 != (BIGNUM *)0x0) {
          iVar2 = *(int *)(*(int *)(param_4 + 0x14) + 4);
          if (a_01->dmax < iVar2) goto LAB_081a21dc;
          goto LAB_081a1ec8;
        }
        goto LAB_081a218d;
      }
      iVar2 = *(int *)(*(int *)(param_4 + 0x14) + 4);
      if (a_01->dmax < iVar2) {
LAB_081a21dc:
        pBVar4 = bn_expand2(a_01,iVar2);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_081a218d;
        iVar2 = *(int *)(*(int *)(param_4 + 0x18) + 4);
        if (a_02->dmax < iVar2) goto LAB_081a2203;
LAB_081a1edb:
        iVar2 = a_03->dmax;
      }
      else {
LAB_081a1ec8:
        iVar2 = *(int *)(*(int *)(param_4 + 0x18) + 4);
        if (iVar2 <= a_02->dmax) goto LAB_081a1edb;
LAB_081a2203:
        pBVar4 = bn_expand2(a_02,iVar2);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_081a218d;
        iVar2 = a_03->dmax;
      }
      if ((iVar2 < 0x28) && (pBVar4 = bn_expand2(a_03,0x28), pBVar4 == (BIGNUM *)0x0))
      goto LAB_081a218d;
      local_6c = 3;
      local_68 = BN_bn2bin(*(BIGNUM **)(param_4 + 0xc),(uchar *)a->d);
      local_64 = a->d;
      local_60 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x10),(uchar *)a_00->d);
      local_5c = a_00->d;
      local_58 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x14),(uchar *)a_01->d);
      local_54 = a_01->d;
      local_50 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x18),(uchar *)a_02->d);
      local_4c = a_02->d;
      iVar2 = (*p_CSwift_AttachKeyParam)(local_7c,&local_6c);
      if (iVar2 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x3d7;
        iVar2 = 0x65;
        goto LAB_081a215c;
      }
      if (iVar2 == 0) {
        local_38 = 0x28;
        local_40 = param_2;
        local_3c = param_1;
        puVar1 = a_03->d;
        *puVar1 = 0;
        puVar1[9] = 0;
        puVar6 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
        for (uVar5 = (uint)((int)puVar1 +
                           (0x28 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc))) >> 2;
            uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar6 = 0;
          puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
        }
        local_34 = puVar1;
        iVar3 = BN_num_bits(*param_3);
        iVar2 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar2 = iVar3 + 0xe;
        }
        BN_bn2bin(*param_3,(uchar *)((int)puVar1 + (0x14 - (iVar2 >> 3))));
        puVar1 = local_34;
        iVar3 = BN_num_bits(param_3[1]);
        iVar2 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar2 = iVar3 + 0xe;
        }
        BN_bn2bin(param_3[1],(uchar *)((int)puVar1 + (0x28 - (iVar2 >> 3))));
        local_70 = &local_78;
        local_74 = 4;
        iVar2 = (*p_CSwift_SimpleRequest)(local_7c,4,&local_40,2,&local_74,1);
        if (iVar2 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = ERR_get_next_error_library();
          }
          iVar3 = 0x3f2;
          goto LAB_081a20f5;
        }
        uVar5 = (uint)(local_78 != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x3dc;
LAB_081a20f5:
        ERR_put_error(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",iVar3);
        __sprintf_chk(local_2d,1,0xd,"%ld",iVar2);
        uVar5 = 0xffffffff;
        ERR_add_error_data(2,"CryptoSwift error number is ",local_2d);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_7c);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar5 = 0xffffffff;
    ERR_put_error(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x3aa);
  }
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_081a2083:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

