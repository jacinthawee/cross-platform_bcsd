
void surewarehk_load_pubkey(ENGINE *param_1,undefined4 param_2)

{
  undefined *puVar1;
  char cVar2;
  int iVar3;
  DSA *d;
  BIGNUM *pBVar4;
  RSA *r;
  int *piVar5;
  int *piVar6;
  ulong *puVar7;
  BIGNUM *pBVar8;
  uint uVar9;
  EVP_PKEY *pkey;
  uint uVar10;
  char local_b1;
  uint local_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined2 uStack_9c;
  undefined local_9a;
  undefined auStack_99 [45];
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined local_58;
  undefined auStack_57 [43];
  int local_2c;
  
  puVar1 = PTR_s_ENGINE_load_pubkey_000f3c6c;
  local_ac = *(undefined4 *)PTR_s_ENGINE_load_pubkey_000f3c6c;
  uStack_a8 = *(undefined4 *)(PTR_s_ENGINE_load_pubkey_000f3c6c + 4);
  uStack_a4 = *(undefined4 *)(PTR_s_ENGINE_load_pubkey_000f3c6c + 8);
  uStack_a0 = *(undefined4 *)(PTR_s_ENGINE_load_pubkey_000f3c6c + 0xc);
  local_b0 = 0;
  local_b1 = '\0';
  uStack_9c = (undefined2)*(undefined4 *)(PTR_s_ENGINE_load_pubkey_000f3c6c + 0x10);
  local_2c = __stack_chk_guard;
  local_9a = (undefined)((uint)*(undefined4 *)(PTR_s_ENGINE_load_pubkey_000f3c6c + 0x10) >> 0x10);
  memset(auStack_99,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    pkey = (EVP_PKEY *)0x0;
    ERR_put_error(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar3 = (*p_surewarehk_Info_Pubkey)(&local_ac,param_2,&local_b0,&local_b1);
    uVar9 = local_b0;
    cVar2 = local_b1;
    if (iVar3 == 1) {
      local_6c = *(undefined4 *)(puVar1 + 0x40);
      uStack_68 = *(undefined4 *)(puVar1 + 0x44);
      uStack_64 = *(undefined4 *)(puVar1 + 0x48);
      uStack_60 = *(undefined4 *)(puVar1 + 0x4c);
      uStack_5c = *(undefined4 *)(puVar1 + 0x50);
      local_58 = (undefined)*(undefined4 *)(puVar1 + 0x54);
      memset(auStack_57,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else {
        if (cVar2 == '\x01') {
          r = RSA_new_method(param_1);
          RSA_set_ex_data(r,rsaHndidx,(void *)0x0);
          *(uint *)&r->field_0x3c = *(uint *)&r->field_0x3c | 0x20;
          pBVar4 = BN_new();
          *(BIGNUM **)&r->field_0x14 = pBVar4;
          pBVar4 = BN_new();
          *(BIGNUM **)&r->field_0x10 = pBVar4;
          if ((*(BIGNUM **)&r->field_0x14 != (BIGNUM *)0x0) && (pBVar4 != (BIGNUM *)0x0)) {
            uVar10 = uVar9 >> 2;
            bn_expand2(*(BIGNUM **)&r->field_0x14,uVar10);
            bn_expand2(*(BIGNUM **)&r->field_0x10,uVar10);
            if ((uVar10 == (*(undefined4 **)&r->field_0x14)[2]) &&
               (uVar10 == (*(undefined4 **)&r->field_0x10)[2])) {
              iVar3 = (*p_surewarehk_Load_Rsa_Pubkey)
                                (&local_6c,param_2,uVar9,**(undefined4 **)&r->field_0x10,
                                 **(undefined4 **)&r->field_0x14);
              surewarehk_error_handling(&local_6c,0x6a,iVar3);
              if (iVar3 == 1) {
                piVar5 = *(int **)&r->field_0x14;
                piVar5[1] = uVar10;
                if (uVar10 == 0) {
                  *(undefined4 *)(*(int *)&r->field_0x10 + 4) = 0;
                }
                else {
                  iVar3 = (uVar10 + 0x3fffffff) * 4;
                  piVar6 = (int *)(*piVar5 + iVar3);
                  uVar9 = uVar10;
                  do {
                    if (*piVar6 != 0) break;
                    uVar9 = uVar9 - 1;
                    piVar6 = piVar6 + -1;
                  } while (uVar9 != 0);
                  piVar6 = *(int **)&r->field_0x10;
                  piVar5[1] = uVar9;
                  piVar6[1] = uVar10;
                  piVar5 = (int *)(*piVar6 + iVar3);
                  do {
                    if (*piVar5 != 0) break;
                    uVar10 = uVar10 - 1;
                    piVar5 = piVar5 + -1;
                  } while (uVar10 != 0);
                  piVar6[1] = uVar10;
                }
                pkey = EVP_PKEY_new();
                EVP_PKEY_assign(pkey,6,r);
                goto LAB_000f3980;
              }
              if (SUREWARE_lib_error_code == 0) {
                SUREWARE_lib_error_code = ERR_get_next_error_library();
              }
              ERR_put_error(SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
            }
          }
          pkey = (EVP_PKEY *)0x0;
          RSA_free(r);
          goto LAB_000f3980;
        }
        if (cVar2 == '\x02') {
          d = DSA_new_method(param_1);
          DSA_set_ex_data(d,dsaHndidx,(void *)0x0);
          pBVar4 = BN_new();
          d->pub_key = pBVar4;
          pBVar4 = BN_new();
          d->p = pBVar4;
          pBVar4 = BN_new();
          d->q = pBVar4;
          pBVar4 = BN_new();
          d->g = pBVar4;
          if ((((d->pub_key != (BIGNUM *)0x0) && (d->p != (BIGNUM *)0x0)) && (d->q != (BIGNUM *)0x0)
              ) && (pBVar4 != (BIGNUM *)0x0)) {
            uVar10 = uVar9 >> 2;
            bn_expand2(d->pub_key,uVar10);
            bn_expand2(d->p,uVar10);
            bn_expand2(d->q,5);
            bn_expand2(d->g,uVar10);
            if (((uVar10 == d->pub_key->dmax) && (uVar10 == d->p->dmax)) &&
               ((d->q->dmax == 5 && (uVar10 == d->g->dmax)))) {
              iVar3 = (*p_surewarehk_Load_Dsa_Pubkey)
                                (&local_6c,param_2,uVar9,d->pub_key->d,d->p->d,d->q->d,d->g->d);
              surewarehk_error_handling(&local_6c,0x6a,iVar3);
              if (iVar3 == 1) {
                pBVar4 = d->pub_key;
                pBVar4->top = uVar10;
                if (uVar10 == 0) {
                  d->p->top = 0;
                }
                else {
                  puVar7 = pBVar4->d + uVar10 + 0x3fffffff;
                  uVar9 = uVar10;
                  do {
                    if (*puVar7 != 0) break;
                    uVar9 = uVar9 - 1;
                    puVar7 = puVar7 + -1;
                  } while (uVar9 != 0);
                  pBVar8 = d->p;
                  pBVar4->top = uVar9;
                  pBVar8->top = uVar10;
                  puVar7 = pBVar8->d + uVar10 + 0x3fffffff;
                  uVar9 = uVar10;
                  do {
                    if (*puVar7 != 0) break;
                    uVar9 = uVar9 - 1;
                    puVar7 = puVar7 + -1;
                  } while (uVar9 != 0);
                  pBVar8->top = uVar9;
                }
                pBVar4 = d->q;
                iVar3 = 5;
                pBVar4->top = 5;
                puVar7 = pBVar4->d + 4;
                do {
                  if (*puVar7 != 0) break;
                  iVar3 = iVar3 + -1;
                  puVar7 = puVar7 + -1;
                } while (iVar3 != 0);
                pBVar8 = d->g;
                pBVar4->top = iVar3;
                pBVar8->top = uVar10;
                if (uVar10 != 0) {
                  puVar7 = pBVar8->d + uVar10 + 0x3fffffff;
                  do {
                    if (*puVar7 != 0) break;
                    uVar10 = uVar10 - 1;
                    puVar7 = puVar7 + -1;
                  } while (uVar10 != 0);
                  pBVar8->top = uVar10;
                }
                pkey = EVP_PKEY_new();
                EVP_PKEY_assign(pkey,0x74,d);
                goto LAB_000f3980;
              }
              ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
            }
          }
          pkey = (EVP_PKEY *)0x0;
          DSA_free(d);
          goto LAB_000f3980;
        }
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
      pkey = (EVP_PKEY *)0x0;
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      pkey = (EVP_PKEY *)0x0;
      ERR_add_error_data(1,&local_ac);
    }
  }
LAB_000f3980:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pkey);
}

