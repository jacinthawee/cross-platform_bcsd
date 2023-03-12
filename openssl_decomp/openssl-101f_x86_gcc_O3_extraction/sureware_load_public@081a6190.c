
EVP_PKEY * __regparm3
sureware_load_public
          (ENGINE *param_1_00,undefined4 param_2_00,void *param_3,uint param_1,char param_2)

{
  undefined4 *puVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int *piVar5;
  int *piVar6;
  DSA *d;
  BIGNUM *pBVar7;
  EVP_PKEY *pkey;
  RSA *r;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int in_GS_OFFSET;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [10];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_60 = 0x65727573;
  local_5c = 0x65726177;
  local_58 = 0x616f6c5f;
  puVar11 = local_48;
  for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  local_54 = 0x75705f64;
  local_50 = 0x63696c62;
  local_4c = 0;
  if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) || (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)
     ) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
    pkey = (EVP_PKEY *)0x0;
  }
  else if (param_2 == '\x01') {
    r = RSA_new_method(param_1_00);
    RSA_set_ex_data(r,rsaHndidx,param_3);
    *(uint *)&r->field_0x3c = *(uint *)&r->field_0x3c | 0x20;
    pBVar7 = BN_new();
    *(BIGNUM **)&r->field_0x14 = pBVar7;
    pBVar7 = BN_new();
    *(BIGNUM **)&r->field_0x10 = pBVar7;
    uVar10 = param_1 >> 2;
    bn_expand2(*(BIGNUM **)&r->field_0x14,uVar10);
    bn_expand2(*(BIGNUM **)&r->field_0x10,uVar10);
    puVar11 = *(undefined4 **)&r->field_0x14;
    if ((((puVar11 != (undefined4 *)0x0) && (uVar10 == puVar11[2])) &&
        (puVar1 = *(undefined4 **)&r->field_0x10, puVar1 != (undefined4 *)0x0)) &&
       (uVar10 == puVar1[2])) {
      iVar9 = (*p_surewarehk_Load_Rsa_Pubkey)(&local_60,param_2_00,param_1,*puVar1,*puVar11);
      surewarehk_error_handling();
      if (iVar9 == 1) {
        piVar5 = *(int **)&r->field_0x14;
        piVar5[1] = uVar10;
        if (uVar10 == 0) {
          *(undefined4 *)(*(int *)&r->field_0x10 + 4) = 0;
        }
        else {
          uVar8 = uVar10;
          do {
            if (*(int *)(*piVar5 + -4 + uVar8 * 4) != 0) break;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
          piVar6 = *(int **)&r->field_0x10;
          piVar5[1] = uVar8;
          piVar6[1] = uVar10;
          do {
            if (*(int *)(*piVar6 + -4 + uVar10 * 4) != 0) break;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
          piVar6[1] = uVar10;
        }
        pkey = EVP_PKEY_new();
        EVP_PKEY_assign(pkey,6,r);
        goto LAB_081a62ac;
      }
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
    }
    RSA_free(r);
    pkey = (EVP_PKEY *)0x0;
  }
  else if (param_2 == '\x02') {
    d = DSA_new_method(param_1_00);
    DSA_set_ex_data(d,dsaHndidx,param_3);
    pBVar7 = BN_new();
    d->pub_key = pBVar7;
    pBVar7 = BN_new();
    d->p = pBVar7;
    pBVar7 = BN_new();
    d->q = pBVar7;
    pBVar7 = BN_new();
    d->g = pBVar7;
    uVar10 = param_1 >> 2;
    bn_expand2(d->pub_key,uVar10);
    bn_expand2(d->p,uVar10);
    bn_expand2(d->q,5);
    bn_expand2(d->g,uVar10);
    pBVar7 = d->pub_key;
    if (((pBVar7 != (BIGNUM *)0x0) && (uVar10 == pBVar7->dmax)) &&
       ((pBVar2 = d->p, pBVar2 != (BIGNUM *)0x0 && (uVar10 == pBVar2->dmax)))) {
      pBVar3 = d->q;
      if (((pBVar3 != (BIGNUM *)0x0) && (pBVar3->dmax == 5)) &&
         ((pBVar4 = d->g, pBVar4 != (BIGNUM *)0x0 && (uVar10 == pBVar4->dmax)))) {
        iVar9 = (*p_surewarehk_Load_Dsa_Pubkey)
                          (&local_60,param_2_00,param_1,pBVar7->d,pBVar2->d,pBVar3->d,pBVar4->d);
        surewarehk_error_handling();
        if (iVar9 == 1) {
          pBVar7 = d->pub_key;
          pBVar7->top = uVar10;
          if (uVar10 == 0) {
            d->p->top = 0;
          }
          else {
            uVar8 = uVar10;
            do {
              if (pBVar7->d[uVar8 - 1] != 0) break;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
            pBVar7->top = uVar8;
            pBVar7 = d->p;
            pBVar7->top = uVar10;
            uVar8 = uVar10;
            do {
              if (pBVar7->d[uVar8 - 1] != 0) break;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
            pBVar7->top = uVar8;
          }
          pBVar7 = d->q;
          iVar9 = 5;
          pBVar7->top = 5;
          do {
            if (pBVar7->d[iVar9 + -1] != 0) break;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          pBVar7->top = iVar9;
          pBVar7 = d->g;
          pBVar7->top = uVar10;
          if (uVar10 != 0) {
            do {
              if (pBVar7->d[uVar10 - 1] != 0) break;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
            pBVar7->top = uVar10;
          }
          pkey = EVP_PKEY_new();
          EVP_PKEY_assign(pkey,0x74,d);
          goto LAB_081a62ac;
        }
        ERR_SUREWARE_error_constprop_5();
      }
    }
    DSA_free(d);
    pkey = (EVP_PKEY *)0x0;
  }
  else {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",0x2f4);
    pkey = (EVP_PKEY *)0x0;
  }
LAB_081a62ac:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

