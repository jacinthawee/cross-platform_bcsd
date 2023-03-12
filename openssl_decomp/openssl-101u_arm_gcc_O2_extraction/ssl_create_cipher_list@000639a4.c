
/* WARNING: Type propagation algorithm not settling */

_STACK * ssl_create_cipher_list(int param_1,_STACK **param_2,_STACK **param_3,char *param_4)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  _STACK *p_Var6;
  int *piVar7;
  _STACK *p_Var8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined *puVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  _STACK *p_Var18;
  int *piVar19;
  _STACK *p_Var20;
  undefined *puVar21;
  uint uVar22;
  _STACK *p_Var23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  _func_257 *p_Var31;
  int iVar32;
  int iVar33;
  _STACK *p_Var34;
  _STACK *p_Var35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  bool bVar39;
  char *local_4c;
  _STACK *local_38;
  _STACK *local_34;
  int *local_30;
  int *local_2c [2];
  
  piVar7 = (int *)(uint)(param_2 == (_STACK **)0x0 || param_4 == (char *)0x0);
  local_38 = (_STACK *)0x0;
  local_34 = (_STACK *)0x0;
  if (param_2 == (_STACK **)0x0 || param_4 == (char *)0x0) {
    return (_STACK *)0x0;
  }
  if (param_3 == (_STACK **)0x0) {
    return (_STACK *)0x0;
  }
  local_30 = piVar7;
  local_2c[0] = piVar7;
  pEVar1 = EVP_PKEY_asn1_find_str((ENGINE **)&local_30,"gost94",-1);
  if ((pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (iVar2 = EVP_PKEY_asn1_get0_info
                        ((int *)local_2c,piVar7,piVar7,(char **)piVar7,(char **)piVar7,pEVar1),
     iVar2 < 1)) {
    local_2c[0] = piVar7;
  }
  if (local_30 != (int *)0x0) {
    ENGINE_finish((ENGINE *)local_30);
  }
  piVar7 = local_2c[0];
  local_30 = (int *)0x0;
  local_2c[0] = (int *)0x0;
  pEVar1 = EVP_PKEY_asn1_find_str((ENGINE **)&local_30,"gost2001",-1);
  if (piVar7 == (int *)0x0) {
    uVar22 = 0x128;
  }
  else {
    uVar22 = 0x28;
  }
  if ((pEVar1 != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (iVar2 = EVP_PKEY_asn1_get0_info
                        ((int *)local_2c,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,pEVar1),
     iVar2 < 1)) {
    local_2c[0] = (int *)0x0;
  }
  if (local_30 != (int *)0x0) {
    ENGINE_finish((ENGINE *)local_30);
  }
  if (local_2c[0] == (int *)0x0) {
    uVar22 = uVar22 | 0x200;
  }
  bVar39 = (uVar22 & 0x300) != 0x300;
  uVar36 = 0xfffffde9;
  if (bVar39) {
    uVar36 = 0xffffffe9;
  }
  uVar37 = 0x216;
  if (bVar39) {
    uVar37 = 0x16;
  }
  if (ssl_cipher_methods._4_4_ == 0) {
    uVar9 = 2;
  }
  else {
    uVar9 = 0;
  }
  if (ssl_cipher_methods._0_4_ == 0) {
    uVar9 = uVar9 | 1;
  }
  if (ssl_cipher_methods._8_4_ == 0) {
    uVar3 = 4;
  }
  else {
    uVar3 = 0;
  }
  if (ssl_cipher_methods._12_4_ == 0) {
    uVar24 = 8;
  }
  else {
    uVar24 = 0;
  }
  if (ssl_cipher_methods._16_4_ == 0) {
    uVar10 = 0x10;
  }
  else {
    uVar10 = 0;
  }
  if (ssl_cipher_methods._24_4_ == 0) {
    uVar15 = 0x40;
  }
  else {
    uVar15 = 0;
  }
  if (ssl_cipher_methods._28_4_ == 0) {
    uVar4 = 0x80;
  }
  else {
    uVar4 = 0;
  }
  if (ssl_cipher_methods._48_4_ == 0) {
    uVar11 = 0x1000;
  }
  else {
    uVar11 = 0;
  }
  if (ssl_cipher_methods._52_4_ == 0) {
    uVar16 = 0x2000;
  }
  else {
    uVar16 = 0;
  }
  if (ssl_cipher_methods._32_4_ == 0) {
    uVar5 = 0x100;
  }
  else {
    uVar5 = 0;
  }
  if (ssl_cipher_methods._36_4_ == 0) {
    uVar12 = 0x200;
  }
  else {
    uVar12 = 0;
  }
  if (ssl_digest_methods._4_4_ == 0) {
    uVar25 = 2;
  }
  else {
    uVar25 = 0;
  }
  if (ssl_digest_methods._0_4_ == 0) {
    uVar25 = uVar25 | 1;
  }
  if (ssl_digest_methods._16_4_ == 0) {
    uVar28 = 0x10;
  }
  else {
    uVar28 = 0;
  }
  if (ssl_cipher_methods._40_4_ == 0) {
    uVar38 = 0x400;
  }
  else {
    uVar38 = 0;
  }
  if (ssl_digest_methods._20_4_ == 0) {
    uVar26 = 0x20;
  }
  else {
    uVar26 = 0;
  }
  if (ssl_cipher_methods._44_4_ == 0) {
    uVar13 = 0x800;
  }
  else {
    uVar13 = 0;
  }
  if (ssl_digest_methods._8_4_ == 0) {
    uVar29 = 4;
  }
  else {
    uVar29 = 0;
  }
  uVar13 = uVar13 | uVar5 | uVar9 | uVar3 | uVar24 | uVar10 | uVar15 | uVar4 | uVar11 | uVar16 |
                    uVar12 | uVar38;
  if (ssl_digest_methods._12_4_ == 0) {
    uVar9 = 8;
  }
  else if (DAT_0018ce6c == 0) {
    uVar9 = 8;
  }
  else {
    uVar9 = 0;
  }
  uVar9 = uVar9 | uVar25 | uVar28 | uVar26 | uVar29;
  iVar2 = (**(code **)(param_1 + 0x54))();
  p_Var6 = (_STACK *)CRYPTO_malloc(iVar2 * 0x14,"ssl_ciph.c",0x584);
  if (p_Var6 == (_STACK *)0x0) {
    ERR_put_error(0x14,0xa6,0x41,"ssl_ciph.c",0x586);
    return (_STACK *)0x0;
  }
  if (iVar2 < 1) {
LAB_00064156:
    p_Var20 = local_38;
    if (local_34 != (_STACK *)0x0) {
      p_Var8 = local_34;
      if (local_38 != (_STACK *)0x0) goto LAB_00063c88;
      goto LAB_00064162;
    }
LAB_00064174:
    local_34 = (_STACK *)0x0;
  }
  else {
    iVar27 = 0;
    iVar32 = 0;
    do {
      iVar33 = iVar32 + 1;
      piVar7 = (int *)(**(code **)(param_1 + 0x58))(iVar32);
      iVar30 = iVar27;
      if ((((piVar7 != (int *)0x0) && (*piVar7 != 0)) && ((uVar37 & piVar7[3]) == 0)) &&
         (((uVar22 & piVar7[4]) == 0 && ((uVar13 & piVar7[5]) == 0)))) {
        bVar39 = (piVar7[6] & uVar9) == 0;
        if (bVar39) {
          iVar30 = iVar27 + 1;
          p_Var6[iVar27].num = (int)piVar7;
        }
        if (bVar39) {
          p_Var6[iVar27].num_alloc = 0;
        }
        if (bVar39) {
          p_Var6[iVar27].comp = (_func_257 *)0x0;
        }
        if (bVar39) {
          p_Var6[iVar27].data = (char **)0x0;
        }
      }
      iVar27 = iVar30;
      iVar32 = iVar33;
    } while (iVar33 != iVar2);
    if (iVar30 == 0) goto LAB_00064156;
    p_Var6->comp = (_func_257 *)0x0;
    local_34 = p_Var6;
    if (iVar30 != 1) {
      if (iVar30 != 2) {
        piVar7 = (int *)(iVar30 + -1);
      }
      p_Var6->num_alloc = (int)(p_Var6 + 1);
      if (iVar30 != 2) {
        piVar17 = (int *)0x1;
        p_Var20 = p_Var6 + 2;
        do {
          piVar17 = (int *)((int)piVar17 + 1);
          p_Var20[-1].num_alloc = (int)p_Var20;
          p_Var20[-1].comp = (_func_257 *)(p_Var20 + -2);
          p_Var20 = p_Var20 + 1;
        } while (piVar17 != piVar7);
      }
      p_Var6[iVar30 + -1].comp = (_func_257 *)(p_Var6 + iVar30 + -2);
      local_34 = p_Var6 + iVar30 + -1;
    }
    local_34->num_alloc = 0;
    local_38 = p_Var6;
    p_Var20 = p_Var6;
    p_Var8 = local_34;
LAB_00063c88:
    do {
      p_Var18 = (_STACK *)p_Var20->num_alloc;
      if ((*(int *)(p_Var20->num + 0xc) << 0x18 < 0) && (p_Var20->data == (char **)0x0)) {
        if (p_Var20 != local_34) {
          p_Var31 = p_Var20->comp;
          if (local_38 == p_Var20) {
            local_38 = p_Var18;
          }
          p_Var34 = p_Var18;
          if (p_Var31 != (_func_257 *)0x0) {
            *(_STACK **)(p_Var31 + 0xc) = p_Var18;
            p_Var34 = (_STACK *)p_Var20->num_alloc;
          }
          if (p_Var34 != (_STACK *)0x0) {
            p_Var34->comp = p_Var31;
          }
          local_34->num_alloc = (int)p_Var20;
          p_Var20->comp = (_func_257 *)local_34;
          p_Var20->num_alloc = 0;
          local_34 = p_Var20;
        }
        p_Var20->data = (char **)0x1;
      }
    } while ((p_Var8 != p_Var20) && (p_Var20 = p_Var18, p_Var18 != (_STACK *)0x0));
    p_Var20 = local_38;
    p_Var8 = local_34;
    if (local_38 != (_STACK *)0x0) {
      do {
        p_Var18 = (_STACK *)p_Var8->comp;
        if ((*(int *)(p_Var8->num + 0xc) << 0x18 < 0) && (p_Var8->data != (char **)0x0)) {
          if (p_Var8 != p_Var20) {
            iVar27 = p_Var8->num_alloc;
            if (p_Var8 == local_34) {
              local_34 = p_Var18;
            }
            p_Var34 = p_Var18;
            if (iVar27 != 0) {
              *(_STACK **)(iVar27 + 0x10) = p_Var18;
              p_Var34 = (_STACK *)p_Var8->comp;
            }
            if (p_Var34 != (_STACK *)0x0) {
              p_Var34->num_alloc = iVar27;
            }
            p_Var20->comp = (_func_257 *)p_Var8;
            p_Var8->num_alloc = (int)p_Var20;
            p_Var8->comp = (_func_257 *)0x0;
            p_Var20 = p_Var8;
          }
          p_Var8->data = (char **)0x0;
        }
      } while ((p_Var8 != local_38) && (p_Var8 = p_Var18, p_Var18 != (_STACK *)0x0));
      if (local_34 == (_STACK *)0x0) goto LAB_00064174;
      p_Var18 = p_Var20;
      p_Var8 = local_34;
      if (p_Var20 != (_STACK *)0x0) {
        do {
          p_Var34 = (_STACK *)p_Var18->num_alloc;
          if (((*(uint *)(p_Var18->num + 0x14) & 0x30c0) != 0) && (p_Var18->data == (char **)0x0)) {
            if (p_Var18 != p_Var8) {
              p_Var31 = p_Var18->comp;
              if (p_Var18 == p_Var20) {
                p_Var20 = p_Var34;
              }
              p_Var35 = p_Var34;
              if (p_Var31 != (_func_257 *)0x0) {
                *(_STACK **)(p_Var31 + 0xc) = p_Var34;
                p_Var35 = (_STACK *)p_Var18->num_alloc;
              }
              if (p_Var35 != (_STACK *)0x0) {
                p_Var35->comp = p_Var31;
              }
              p_Var8->num_alloc = (int)p_Var18;
              p_Var18->comp = (_func_257 *)p_Var8;
              p_Var18->num_alloc = 0;
              p_Var8 = p_Var18;
            }
            p_Var18->data = (char **)0x1;
          }
        } while ((p_Var18 != local_34) && (p_Var18 = p_Var34, p_Var34 != (_STACK *)0x0));
        p_Var34 = p_Var20;
        local_34 = p_Var8;
        p_Var18 = p_Var8;
        if (p_Var20 != (_STACK *)0x0) {
          do {
            p_Var35 = (_STACK *)p_Var34->num_alloc;
            if (p_Var34->data == (char **)0x0) {
              if (p_Var34 != p_Var18) {
                p_Var31 = p_Var34->comp;
                if (p_Var34 == p_Var20) {
                  p_Var20 = p_Var35;
                }
                p_Var23 = p_Var35;
                if (p_Var31 != (_func_257 *)0x0) {
                  *(_STACK **)(p_Var31 + 0xc) = p_Var35;
                  p_Var23 = (_STACK *)p_Var34->num_alloc;
                }
                if (p_Var23 != (_STACK *)0x0) {
                  p_Var23->comp = p_Var31;
                }
                p_Var18->num_alloc = (int)p_Var34;
                p_Var34->comp = (_func_257 *)p_Var18;
                p_Var34->num_alloc = 0;
                p_Var18 = p_Var34;
              }
              p_Var34->data = (char **)0x1;
            }
          } while ((p_Var8 != p_Var34) && (p_Var34 = p_Var35, p_Var35 != (_STACK *)0x0));
          p_Var8 = p_Var20;
          local_34 = p_Var18;
          if (p_Var20 != (_STACK *)0x0) {
            do {
              p_Var34 = (_STACK *)p_Var8->num_alloc;
              if (((*(int *)(p_Var8->num + 0x18) << 0x1f < 0) && (p_Var8->data != (char **)0x0)) &&
                 (p_Var8 != local_34)) {
                p_Var31 = p_Var8->comp;
                if (p_Var8 == p_Var20) {
                  p_Var20 = p_Var34;
                }
                p_Var35 = p_Var34;
                if (p_Var31 != (_func_257 *)0x0) {
                  *(_STACK **)(p_Var31 + 0xc) = p_Var34;
                  p_Var35 = (_STACK *)p_Var8->num_alloc;
                }
                if (p_Var35 != (_STACK *)0x0) {
                  p_Var35->comp = p_Var31;
                }
                local_34->num_alloc = (int)p_Var8;
                p_Var8->comp = (_func_257 *)local_34;
                p_Var8->num_alloc = 0;
                local_34 = p_Var8;
              }
            } while ((p_Var18 != p_Var8) && (p_Var8 = p_Var34, p_Var34 != (_STACK *)0x0));
            if (local_34 == (_STACK *)0x0) goto LAB_00064174;
            p_Var18 = p_Var20;
            p_Var8 = local_34;
            if (p_Var20 != (_STACK *)0x0) {
              do {
                p_Var34 = (_STACK *)p_Var18->num_alloc;
                if (((*(int *)(p_Var18->num + 0x10) << 0x1d < 0) && (p_Var18->data != (char **)0x0))
                   && (p_Var18 != p_Var8)) {
                  p_Var31 = p_Var18->comp;
                  if (p_Var18 == p_Var20) {
                    p_Var20 = p_Var34;
                  }
                  p_Var35 = p_Var34;
                  if (p_Var31 != (_func_257 *)0x0) {
                    *(_STACK **)(p_Var31 + 0xc) = p_Var34;
                    p_Var35 = (_STACK *)p_Var18->num_alloc;
                  }
                  if (p_Var35 != (_STACK *)0x0) {
                    p_Var35->comp = p_Var31;
                  }
                  p_Var8->num_alloc = (int)p_Var18;
                  p_Var18->comp = (_func_257 *)p_Var8;
                  p_Var18->num_alloc = 0;
                  p_Var8 = p_Var18;
                }
              } while ((p_Var18 != local_34) && (p_Var18 = p_Var34, p_Var34 != (_STACK *)0x0));
              local_34 = p_Var8;
              p_Var18 = p_Var20;
              if (p_Var8 != (_STACK *)0x0) {
                do {
                  if (p_Var18 == (_STACK *)0x0) break;
                  p_Var34 = (_STACK *)p_Var18->num_alloc;
                  if (((*(int *)(p_Var18->num + 0x10) << 0x1b < 0) &&
                      (p_Var18->data != (char **)0x0)) && (local_34 != p_Var18)) {
                    p_Var31 = p_Var18->comp;
                    if (p_Var20 == p_Var18) {
                      p_Var20 = p_Var34;
                    }
                    p_Var35 = p_Var34;
                    if (p_Var31 != (_func_257 *)0x0) {
                      *(_STACK **)(p_Var31 + 0xc) = p_Var34;
                      p_Var35 = (_STACK *)p_Var18->num_alloc;
                    }
                    if (p_Var35 != (_STACK *)0x0) {
                      p_Var35->comp = p_Var31;
                    }
                    local_34->num_alloc = (int)p_Var18;
                    p_Var18->comp = (_func_257 *)local_34;
                    p_Var18->num_alloc = 0;
                    local_34 = p_Var18;
                  }
                  bVar39 = p_Var18 != p_Var8;
                  p_Var18 = p_Var34;
                } while (bVar39);
              }
              goto LAB_00063f00;
            }
          }
        }
      }
    }
LAB_00064162:
    p_Var20 = (_STACK *)0x0;
  }
LAB_00063f00:
  local_38 = p_Var20;
  ssl_cipher_apply_rule_isra_1_constprop_4(1,&local_38,&local_34);
  ssl_cipher_apply_rule_isra_1_constprop_4(0x100,&local_38,&local_34);
  ssl_cipher_apply_rule_isra_1_constprop_4(0x10,&local_38,&local_34);
  p_Var20 = local_34;
  p_Var8 = local_38;
  if (local_34 != (_STACK *)0x0) {
    do {
      if (p_Var8 == (_STACK *)0x0) break;
      p_Var18 = (_STACK *)p_Var8->num_alloc;
      if (((*(int *)(p_Var8->num + 0x14) << 0x1d < 0) && (p_Var8->data != (char **)0x0)) &&
         (p_Var20 != p_Var8)) {
        p_Var31 = p_Var8->comp;
        if (local_38 == p_Var8) {
          local_38 = p_Var18;
        }
        p_Var34 = p_Var18;
        if (p_Var31 != (_func_257 *)0x0) {
          *(_STACK **)(p_Var31 + 0xc) = p_Var18;
          p_Var34 = (_STACK *)p_Var8->num_alloc;
        }
        if (p_Var34 != (_STACK *)0x0) {
          p_Var34->comp = p_Var31;
        }
        p_Var20->num_alloc = (int)p_Var8;
        p_Var8->comp = (_func_257 *)p_Var20;
        p_Var8->num_alloc = 0;
        p_Var20 = p_Var8;
      }
      bVar39 = p_Var8 != local_34;
      p_Var8 = p_Var18;
    } while (bVar39);
  }
  local_34 = p_Var20;
  iVar27 = ssl_cipher_strength_sort(&local_38,&local_34);
  if (iVar27 != 0) {
    p_Var20 = local_38;
    p_Var8 = local_34;
    if (local_38 != (_STACK *)0x0) {
      do {
        if (p_Var8 == (_STACK *)0x0) break;
        p_Var18 = (_STACK *)p_Var8->comp;
        if (p_Var8->data != (char **)0x0) {
          if (p_Var20 != p_Var8) {
            iVar27 = p_Var8->num_alloc;
            if (local_34 == p_Var8) {
              local_34 = p_Var18;
            }
            p_Var34 = p_Var18;
            if (iVar27 != 0) {
              *(_STACK **)(iVar27 + 0x10) = p_Var18;
              p_Var34 = (_STACK *)p_Var8->comp;
            }
            if (p_Var34 != (_STACK *)0x0) {
              p_Var34->num_alloc = iVar27;
            }
            p_Var20->comp = (_func_257 *)p_Var8;
            p_Var8->num_alloc = (int)p_Var20;
            p_Var8->comp = (_func_257 *)0x0;
            p_Var20 = p_Var8;
          }
          p_Var8->data = (char **)0x0;
        }
        bVar39 = p_Var8 != local_38;
        p_Var8 = p_Var18;
      } while (bVar39);
    }
    local_38 = p_Var20;
    piVar7 = (int *)CRYPTO_malloc((iVar2 + 0x4b) * 4,"ssl_ciph.c",0x5d5);
    if (piVar7 == (int *)0x0) {
      CRYPTO_free(p_Var6);
      ERR_put_error(0x14,0xa6,0x41,"ssl_ciph.c",0x5d8);
      return (_STACK *)0x0;
    }
    piVar17 = piVar7;
    puVar14 = PTR_cipher_aliases_000641d0;
    for (p_Var20 = local_38; PTR_cipher_aliases_000641d0 = puVar14, p_Var20 != (_STACK *)0x0;
        p_Var20 = (_STACK *)p_Var20->num_alloc) {
      *piVar17 = p_Var20->num;
      piVar17 = piVar17 + 1;
      puVar14 = PTR_cipher_aliases_000641d0;
    }
    puVar21 = puVar14 + 0xde0;
    do {
      piVar19 = piVar17;
      if (((((*(uint *)(puVar14 + 0xc) == 0) || ((*(uint *)(puVar14 + 0xc) & uVar36) != 0)) &&
           ((*(uint *)(puVar14 + 0x10) == 0 || ((*(uint *)(puVar14 + 0x10) & ~uVar22) != 0)))) &&
          ((*(uint *)(puVar14 + 0x14) == 0 || ((*(uint *)(puVar14 + 0x14) & ~uVar13) != 0)))) &&
         ((*(uint *)(puVar14 + 0x18) == 0 || ((*(uint *)(puVar14 + 0x18) & ~uVar9) != 0)))) {
        piVar19 = piVar17 + 1;
        *piVar17 = (int)puVar14;
      }
      puVar14 = puVar14 + 0x30;
      piVar17 = piVar19;
    } while (puVar14 != puVar21);
    *piVar19 = 0;
    iVar2 = strncmp(param_4,"DEFAULT",7);
    local_4c = param_4;
    if (iVar2 == 0) {
      iVar2 = ssl_cipher_process_rulestr
                        ("ALL:!EXPORT:!LOW:!aNULL:!eNULL:!SSLv2",&local_38,&local_34,piVar7);
      if (param_4[7] == ':') {
        local_4c = param_4 + 8;
      }
      else {
        local_4c = param_4 + 7;
      }
      if (iVar2 == 0) {
        CRYPTO_free(piVar7);
        goto LAB_0006412e;
      }
    }
    if (*local_4c == '\0') {
      CRYPTO_free(piVar7);
    }
    else {
      iVar2 = ssl_cipher_process_rulestr(local_4c,&local_38,&local_34,piVar7);
      CRYPTO_free(piVar7);
      if (iVar2 == 0) goto LAB_0006412e;
    }
    p_Var8 = sk_new_null();
    p_Var20 = local_38;
    if (p_Var8 == (_STACK *)0x0) {
      CRYPTO_free(p_Var6);
    }
    else {
      for (; p_Var20 != (_STACK *)0x0; p_Var20 = (_STACK *)p_Var20->num_alloc) {
        while (p_Var20->data == (char **)0x0) {
          p_Var20 = (_STACK *)p_Var20->num_alloc;
          if (p_Var20 == (_STACK *)0x0) goto LAB_000640ac;
        }
        sk_push(p_Var8,(void *)p_Var20->num);
      }
LAB_000640ac:
      CRYPTO_free(p_Var6);
      p_Var6 = sk_dup(p_Var8);
      if (p_Var6 == (_STACK *)0x0) {
        sk_free(p_Var8);
        p_Var8 = p_Var6;
      }
      else {
        if (*param_2 != (_STACK *)0x0) {
          sk_free(*param_2);
        }
        *param_2 = p_Var8;
        if (*param_3 != (_STACK *)0x0) {
          sk_free(*param_3);
        }
        *param_3 = p_Var6;
        sk_set_cmp_func(p_Var6,ssl_cipher_ptr_id_cmp + 1);
        sk_sort(*param_3);
      }
    }
    return p_Var8;
  }
LAB_0006412e:
  CRYPTO_free(p_Var6);
  return (_STACK *)0x0;
}

