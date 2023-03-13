
EVP_PKEY * __regparm3
sureware_load_public
          (ENGINE *param_1_00,undefined4 param_2_00,void *param_3,uint param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  DSA *d;
  BIGNUM *pBVar3;
  EVP_PKEY *pkey;
  RSA *r;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
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
  puVar7 = local_48;
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  local_54 = 0x75705f64;
  local_50 = 0x63696c62;
  local_4c = 0;
  if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) || (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)
     ) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
  }
  else {
    if (param_2 == '\x01') {
      r = RSA_new_method(param_1_00);
      RSA_set_ex_data(r,rsaHndidx,param_3);
      *(uint *)&r->field_0x3c = *(uint *)&r->field_0x3c | 0x20;
      pBVar3 = BN_new();
      *(BIGNUM **)&r->field_0x14 = pBVar3;
      pBVar3 = BN_new();
      *(BIGNUM **)&r->field_0x10 = pBVar3;
      if ((*(BIGNUM **)&r->field_0x14 != (BIGNUM *)0x0) && (pBVar3 != (BIGNUM *)0x0)) {
        uVar6 = param_1 >> 2;
        bn_expand2(*(BIGNUM **)&r->field_0x14,uVar6);
        bn_expand2(*(BIGNUM **)&r->field_0x10,uVar6);
        if ((uVar6 == (*(undefined4 **)&r->field_0x14)[2]) &&
           (uVar6 == (*(undefined4 **)&r->field_0x10)[2])) {
          iVar5 = (*p_surewarehk_Load_Rsa_Pubkey)
                            (&local_60,param_2_00,param_1,**(undefined4 **)&r->field_0x10,
                             **(undefined4 **)&r->field_0x14);
          surewarehk_error_handling();
          if (iVar5 == 1) {
            piVar1 = *(int **)&r->field_0x14;
            piVar1[1] = uVar6;
            if (uVar6 == 0) {
              *(undefined4 *)(*(int *)&r->field_0x10 + 4) = 0;
            }
            else {
              uVar4 = uVar6;
              do {
                if (*(int *)(*piVar1 + -4 + uVar4 * 4) != 0) break;
                uVar4 = uVar4 - 1;
              } while (uVar4 != 0);
              piVar2 = *(int **)&r->field_0x10;
              piVar1[1] = uVar4;
              piVar2[1] = uVar6;
              do {
                if (*(int *)(*piVar2 + -4 + uVar6 * 4) != 0) break;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
              piVar2[1] = uVar6;
            }
            pkey = EVP_PKEY_new();
            EVP_PKEY_assign(pkey,6,r);
            goto LAB_081a4d45;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
        }
      }
      RSA_free(r);
      pkey = (EVP_PKEY *)0x0;
      goto LAB_081a4d45;
    }
    if (param_2 == '\x02') {
      d = DSA_new_method(param_1_00);
      DSA_set_ex_data(d,dsaHndidx,param_3);
      pBVar3 = BN_new();
      d->pub_key = pBVar3;
      pBVar3 = BN_new();
      d->p = pBVar3;
      pBVar3 = BN_new();
      d->q = pBVar3;
      pBVar3 = BN_new();
      d->g = pBVar3;
      if ((((d->pub_key != (BIGNUM *)0x0) && (d->p != (BIGNUM *)0x0)) && (d->q != (BIGNUM *)0x0)) &&
         (pBVar3 != (BIGNUM *)0x0)) {
        uVar6 = param_1 >> 2;
        bn_expand2(d->pub_key,uVar6);
        bn_expand2(d->p,uVar6);
        bn_expand2(d->q,5);
        bn_expand2(d->g,uVar6);
        if (((uVar6 == d->pub_key->dmax) && (uVar6 == d->p->dmax)) &&
           ((d->q->dmax == 5 && (uVar6 == d->g->dmax)))) {
          iVar5 = (*p_surewarehk_Load_Dsa_Pubkey)
                            (&local_60,param_2_00,param_1,d->pub_key->d,d->p->d,d->q->d,d->g->d);
          surewarehk_error_handling();
          if (iVar5 == 1) {
            pBVar3 = d->pub_key;
            pBVar3->top = uVar6;
            if (uVar6 == 0) {
              d->p->top = 0;
            }
            else {
              uVar4 = uVar6;
              do {
                if (pBVar3->d[uVar4 - 1] != 0) break;
                uVar4 = uVar4 - 1;
              } while (uVar4 != 0);
              pBVar3->top = uVar4;
              pBVar3 = d->p;
              pBVar3->top = uVar6;
              uVar4 = uVar6;
              do {
                if (pBVar3->d[uVar4 - 1] != 0) break;
                uVar4 = uVar4 - 1;
              } while (uVar4 != 0);
              pBVar3->top = uVar4;
            }
            pBVar3 = d->q;
            iVar5 = 5;
            pBVar3->top = 5;
            do {
              if (pBVar3->d[iVar5 + -1] != 0) break;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            pBVar3->top = iVar5;
            pBVar3 = d->g;
            pBVar3->top = uVar6;
            if (uVar6 != 0) {
              do {
                if (pBVar3->d[uVar6 - 1] != 0) break;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
              pBVar3->top = uVar6;
            }
            pkey = EVP_PKEY_new();
            EVP_PKEY_assign(pkey,0x74,d);
            goto LAB_081a4d45;
          }
          ERR_SUREWARE_error_constprop_5();
        }
      }
      DSA_free(d);
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
    }
  }
  pkey = (EVP_PKEY *)0x0;
LAB_081a4d45:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

