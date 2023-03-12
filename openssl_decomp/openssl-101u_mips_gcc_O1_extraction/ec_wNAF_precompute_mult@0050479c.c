
bool ec_wNAF_precompute_mult(EC_GROUP *param_1,BN_CTX *param_2)

{
  EC_POINT **ppEVar1;
  EC_GROUP **ppEVar2;
  EC_POINT *pEVar3;
  BIGNUM *order;
  int iVar4;
  uint uVar5;
  EC_GROUP *pEVar6;
  EC_GROUP *num;
  EC_POINT **points;
  EC_POINT *pEVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  EC_POINT **ppEVar12;
  EC_GROUP *pEVar13;
  EC_POINT *dst;
  BN_CTX *local_58;
  EC_POINT **local_44;
  EC_GROUP *local_3c;
  EC_GROUP *local_38;
  
  EC_EX_DATA_free_data(param_1 + 0x44,ec_pre_comp_dup,ec_pre_comp_free,ec_pre_comp_clear_free);
  if (param_1 == (EC_GROUP *)0x0) {
    return false;
  }
  ppEVar2 = (EC_GROUP **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x1c,"ec_mult.c",0x67);
  if (ppEVar2 == (EC_GROUP **)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xc4,0x41,"ec_mult.c",0x69);
    return false;
  }
  *ppEVar2 = param_1;
  ppEVar2[2] = (EC_GROUP *)0x0;
  ppEVar2[4] = (EC_GROUP *)0x0;
  ppEVar2[5] = (EC_GROUP *)0x0;
  ppEVar2[1] = (EC_GROUP *)&DAT_00000008;
  ppEVar2[3] = (EC_GROUP *)&SUB_00000004;
  ppEVar2[6] = (EC_GROUP *)0x1;
  pEVar3 = EC_GROUP_get0_generator(param_1);
  if (pEVar3 == (EC_POINT *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbc,0x71,"ec_mult.c",0x2f9);
    if (param_2 != (BN_CTX *)0x0) {
      BN_CTX_end(param_2);
    }
LAB_00504c1c:
    points = (EC_POINT **)0x0;
    bVar11 = false;
    dst = (EC_POINT *)0x0;
    pEVar7 = (EC_POINT *)0x0;
  }
  else {
    if (param_2 == (BN_CTX *)0x0) {
      param_2 = BN_CTX_new();
      local_58 = param_2;
      if (param_2 == (BN_CTX *)0x0) goto LAB_00504c1c;
    }
    else {
      local_58 = (BN_CTX *)0x0;
    }
    BN_CTX_start(param_2);
    order = BN_CTX_get(param_2);
    if ((order == (BIGNUM *)0x0) || (iVar4 = EC_GROUP_get_order(param_1,order,param_2), iVar4 == 0))
    {
      bVar11 = false;
      points = (EC_POINT **)0x0;
      dst = (EC_POINT *)0x0;
      pEVar7 = (EC_POINT *)0x0;
    }
    else if (order->top == 0) {
      bVar11 = false;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbc,0x72,"ec_mult.c",0x30b);
      points = (EC_POINT **)0x0;
      dst = (EC_POINT *)0x0;
      pEVar7 = (EC_POINT *)0x0;
    }
    else {
      uVar5 = BN_num_bits(order);
      if (uVar5 < 800) {
        local_44 = (EC_POINT **)0x8;
        local_3c = (EC_GROUP *)&SUB_00000004;
      }
      else {
        local_44 = (EC_POINT **)0x10;
        if (1999 < uVar5) {
          local_44 = (EC_POINT **)0x20;
        }
        local_3c = (EC_GROUP *)&DAT_00000005;
        if (1999 < uVar5) {
          local_3c = (EC_GROUP *)&DAT_00000006;
        }
      }
      iVar4 = (int)local_44;
      pEVar6 = (EC_GROUP *)(uVar5 + 7 >> 3);
      num = (EC_GROUP *)((int)pEVar6 * (int)local_44);
      points = (EC_POINT **)
               (*(code *)PTR_CRYPTO_malloc_006a7008)((int)(num + 1) * 4,"ec_mult.c",0x325);
      if (points == (EC_POINT **)0x0) {
        uVar8 = 0x327;
LAB_0050499c:
        bVar11 = false;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbc,0x41,"ec_mult.c",uVar8);
        dst = (EC_POINT *)0x0;
        pEVar7 = (EC_POINT *)0x0;
      }
      else {
        points[(int)(num + 1 + -1)] = (EC_POINT *)0x0;
        if (num != (EC_GROUP *)0x0) {
          pEVar13 = (EC_GROUP *)0x0;
          ppEVar12 = points;
          do {
            pEVar13 = pEVar13 + 1;
            pEVar7 = EC_POINT_new(param_1);
            *ppEVar12 = pEVar7;
            if (pEVar7 == (EC_POINT *)0x0) {
              uVar8 = 0x32f;
              goto LAB_0050499c;
            }
            ppEVar12 = ppEVar12 + 1;
          } while (num != pEVar13);
        }
        pEVar7 = EC_POINT_new(param_1);
        if ((pEVar7 == (EC_POINT *)0x0) || (dst = EC_POINT_new(param_1), dst == (EC_POINT *)0x0)) {
          bVar11 = false;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbc,0x41,"ec_mult.c",0x335);
          dst = (EC_POINT *)0x0;
        }
        else {
          iVar9 = EC_POINT_copy(dst,pEVar3);
          if (iVar9 != 0) {
            if (pEVar6 != (EC_GROUP *)0x0) {
              local_38 = (EC_GROUP *)0x0;
              local_44 = points;
              do {
                iVar9 = EC_POINT_dbl(param_1,pEVar7,dst,param_2);
                if (iVar9 == 0) goto LAB_00504d28;
                ppEVar12 = local_44 + 1;
                iVar9 = EC_POINT_copy(*local_44,dst);
                if (iVar9 == 0) goto LAB_00504d28;
                local_44 = local_44 + iVar4;
                do {
                  ppEVar1 = ppEVar12 + -1;
                  pEVar3 = *ppEVar12;
                  ppEVar12 = ppEVar12 + 1;
                  iVar9 = EC_POINT_add(param_1,pEVar3,pEVar7,*ppEVar1,param_2);
                  if (iVar9 == 0) goto LAB_00504d28;
                } while (ppEVar12 != local_44);
                if (local_38 < pEVar6 + -1) {
                  iVar9 = EC_POINT_dbl(param_1,dst,pEVar7,param_2);
                  if (iVar9 == 0) goto LAB_00504d28;
                  iVar9 = 5;
                  do {
                    iVar10 = EC_POINT_dbl(param_1,dst,dst,param_2);
                    if (iVar10 == 0) goto LAB_00504d28;
                    bVar11 = iVar9 != 0;
                    iVar9 = iVar9 + -1;
                  } while (bVar11);
                }
                local_38 = local_38 + 1;
              } while (pEVar6 != local_38);
            }
            iVar4 = EC_POINTs_make_affine(param_1,(size_t)num,points,param_2);
            if (iVar4 != 0) {
              ppEVar2[4] = (EC_GROUP *)points;
              *ppEVar2 = param_1;
              points = (EC_POINT **)0x0;
              ppEVar2[1] = (EC_GROUP *)&DAT_00000008;
              ppEVar2[2] = pEVar6;
              ppEVar2[3] = local_3c;
              ppEVar2[5] = num;
              iVar4 = EC_EX_DATA_set_data(param_1 + 0x44,ppEVar2,ec_pre_comp_dup,ec_pre_comp_free,
                                          ec_pre_comp_clear_free);
              bVar11 = iVar4 != 0;
              if (iVar4 != 0) {
                ppEVar2 = (EC_GROUP **)0x0;
              }
              goto LAB_005049cc;
            }
          }
LAB_00504d28:
          bVar11 = false;
        }
      }
    }
LAB_005049cc:
    BN_CTX_end(param_2);
    if (local_58 != (BN_CTX *)0x0) {
      BN_CTX_free(local_58);
    }
    if (ppEVar2 == (EC_GROUP **)0x0) goto LAB_00504a24;
  }
  iVar4 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(ppEVar2 + 6,0xffffffff,0x24,"ec_mult.c",0x89);
  if (iVar4 < 1) {
    ppEVar12 = (EC_POINT **)ppEVar2[4];
    if (ppEVar12 != (EC_POINT **)0x0) {
      pEVar3 = *ppEVar12;
      if (pEVar3 != (EC_POINT *)0x0) {
        do {
          ppEVar12 = ppEVar12 + 1;
          EC_POINT_free(pEVar3);
          pEVar3 = *ppEVar12;
        } while (pEVar3 != (EC_POINT *)0x0);
        ppEVar12 = (EC_POINT **)ppEVar2[4];
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppEVar12);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(ppEVar2);
  }
LAB_00504a24:
  if (points != (EC_POINT **)0x0) {
    pEVar3 = *points;
    ppEVar12 = points;
    while (pEVar3 != (EC_POINT *)0x0) {
      ppEVar12 = ppEVar12 + 1;
      EC_POINT_free(pEVar3);
      pEVar3 = *ppEVar12;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(points);
  }
  if (pEVar7 != (EC_POINT *)0x0) {
    EC_POINT_free(pEVar7);
  }
  if (dst == (EC_POINT *)0x0) {
    return bVar11;
  }
  EC_POINT_free(dst);
  return bVar11;
}

