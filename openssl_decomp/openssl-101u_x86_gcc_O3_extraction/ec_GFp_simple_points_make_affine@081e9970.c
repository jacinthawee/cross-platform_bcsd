
undefined4 ec_GFp_simple_points_make_affine(int *param_1,int param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM **ptr;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  BN_CTX *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24;
  
  if (param_2 == 0) {
    return 1;
  }
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    if (param_4 == (BN_CTX *)0x0) {
      return 0;
    }
    BN_CTX_start(param_4);
    local_28 = BN_CTX_get(param_4);
    local_24 = BN_CTX_get(param_4);
    if (((local_28 == (BIGNUM *)0x0) || (local_24 == (BIGNUM *)0x0)) ||
       (ptr = (BIGNUM **)CRYPTO_malloc(param_2 * 4,"ecp_smpl.c",0x4f9), local_2c = param_4,
       ptr == (BIGNUM **)0x0)) {
      BN_CTX_end(param_4);
      BN_CTX_free(param_4);
      return 0;
    }
  }
  else {
    BN_CTX_start(param_4);
    local_28 = BN_CTX_get(param_4);
    local_24 = BN_CTX_get(param_4);
    if (((local_24 == (BIGNUM *)0x0) || (local_28 == (BIGNUM *)0x0)) ||
       (ptr = (BIGNUM **)CRYPTO_malloc(param_2 * 4,"ecp_smpl.c",0x4f9), ptr == (BIGNUM **)0x0)) {
      BN_CTX_end(param_4);
      return 0;
    }
    local_2c = (BN_CTX *)0x0;
  }
  iVar4 = 0;
  do {
    pBVar1 = BN_new();
    ptr[iVar4] = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_081e9a17;
    iVar4 = iVar4 + 1;
  } while (param_2 != iVar4);
  if (*(int *)(*param_3 + 0x30) == 0) {
    if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
      pBVar1 = (BIGNUM *)BN_set_word(*ptr,1);
    }
    else {
      pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x98))(param_1,*ptr,param_4);
    }
  }
  else {
    pBVar1 = BN_copy(*ptr,(BIGNUM *)(*param_3 + 0x2c));
  }
  if (pBVar1 != (BIGNUM *)0x0) {
    if (param_2 != 1) {
      iVar4 = 1;
      do {
        if (*(int *)(param_3[iVar4] + 0x30) == 0) {
          pBVar1 = BN_copy(ptr[iVar4],ptr[iVar4 + -1]);
        }
        else {
          pBVar1 = (BIGNUM *)
                   (**(code **)(*param_1 + 0x84))
                             (param_1,ptr[iVar4],ptr[iVar4 + -1],param_3[iVar4] + 0x2c,param_4);
        }
        if (pBVar1 == (BIGNUM *)0x0) goto LAB_081e9a17;
        iVar4 = iVar4 + 1;
      } while (param_2 != iVar4);
    }
    pBVar1 = BN_mod_inverse(local_28,ptr[param_2 + -1],(BIGNUM *)(param_1 + 0x12),param_4);
    if (pBVar1 == (BIGNUM *)0x0) {
      uVar5 = 0;
      ERR_put_error(0x10,0x89,3,"ecp_smpl.c",0x525);
      goto LAB_081e9a19;
    }
    if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
       ((iVar4 = (**(code **)(*param_1 + 0x90))(param_1,local_28,local_28,param_4), iVar4 != 0 &&
        (iVar4 = (**(code **)(*param_1 + 0x90))(param_1,local_28,local_28,param_4), iVar4 != 0)))) {
      for (iVar4 = param_2 + -1; iVar4 != 0; iVar4 = iVar4 + -1) {
        if ((*(int *)(param_3[iVar4] + 0x30) != 0) &&
           (((iVar2 = (**(code **)(*param_1 + 0x84))
                                (param_1,local_24,ptr[iVar4 + -1],local_28,param_4), iVar2 == 0 ||
             (iVar2 = (**(code **)(*param_1 + 0x84))
                                (param_1,local_28,local_28,param_3[iVar4] + 0x2c,param_4),
             iVar2 == 0)) ||
            (pBVar1 = BN_copy((BIGNUM *)(param_3[iVar4] + 0x2c),local_24), pBVar1 == (BIGNUM *)0x0))
           )) goto LAB_081e9a17;
      }
      if ((*(int *)(*param_3 + 0x30) == 0) ||
         (pBVar1 = BN_copy((BIGNUM *)(*param_3 + 0x2c),local_28), pBVar1 != (BIGNUM *)0x0)) {
        iVar4 = 0;
        do {
          iVar2 = param_3[iVar4];
          if (*(int *)(iVar2 + 0x30) != 0) {
            pBVar1 = (BIGNUM *)(iVar2 + 0x2c);
            iVar3 = (**(code **)(*param_1 + 0x88))(param_1,local_28,pBVar1,param_4);
            if (((iVar3 == 0) ||
                (iVar3 = (**(code **)(*param_1 + 0x84))
                                   (param_1,iVar2 + 4,iVar2 + 4,local_28,param_4), iVar3 == 0)) ||
               ((iVar3 = (**(code **)(*param_1 + 0x84))(param_1,local_28,local_28,pBVar1,param_4),
                iVar3 == 0 ||
                (iVar3 = (**(code **)(*param_1 + 0x84))
                                   (param_1,iVar2 + 0x18,iVar2 + 0x18,local_28,param_4), iVar3 == 0)
                ))) goto LAB_081e9a17;
            if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
              iVar3 = BN_set_word(pBVar1,1);
            }
            else {
              iVar3 = (**(code **)(*param_1 + 0x98))(param_1,pBVar1,param_4);
            }
            if (iVar3 == 0) goto LAB_081e9a17;
            *(undefined4 *)(iVar2 + 0x40) = 1;
          }
          iVar4 = iVar4 + 1;
        } while (param_2 != iVar4);
        uVar5 = 1;
        goto LAB_081e9a19;
      }
    }
  }
LAB_081e9a17:
  uVar5 = 0;
LAB_081e9a19:
  BN_CTX_end(param_4);
  if (local_2c != (BN_CTX *)0x0) {
    BN_CTX_free(local_2c);
  }
  iVar4 = 0;
  pBVar1 = *ptr;
  while (pBVar1 != (BIGNUM *)0x0) {
    iVar4 = iVar4 + 1;
    BN_clear_free(pBVar1);
    if (param_2 == iVar4) break;
    pBVar1 = ptr[iVar4];
  }
  CRYPTO_free(ptr);
  return uVar5;
}

