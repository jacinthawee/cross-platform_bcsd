
int X509_policy_check(X509_POLICY_TREE **ptree,int *pexplicit_policy,stack_st_X509 *certs,
                     stack_st_ASN1_OBJECT *policy_oids,uint flags)

{
  int iVar1;
  bool bVar2;
  void *pvVar3;
  int iVar4;
  X509 *x;
  int iVar5;
  uint *puVar6;
  void **tree;
  void *pvVar7;
  ASN1_OBJECT *pAVar8;
  int *piVar9;
  uint **ppuVar10;
  uint *puVar11;
  uint uVar12;
  byte **ptr;
  undefined4 *puVar13;
  _STACK *st;
  _STACK *p_Var14;
  int iVar15;
  int iVar16;
  X509 **ppXVar17;
  int iVar18;
  undefined4 *puVar19;
  _STACK **pp_Var20;
  void **ppvVar21;
  undefined4 *puVar22;
  int iVar23;
  int in_GS_OFFSET;
  int local_50;
  int local_4c;
  int local_48;
  int local_3c;
  _STACK *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (_STACK *)0x0;
  *ptree = (X509_POLICY_TREE *)0x0;
  *pexplicit_policy = 0;
  pvVar3 = (void *)sk_num(&certs->stack);
  iVar4 = (int)pvVar3 + 1;
  iVar15 = 0;
  if ((flags & 0x100) == 0) {
    iVar15 = iVar4;
  }
  local_4c = 0;
  if ((flags & 0x200) == 0) {
    local_4c = iVar4;
  }
  iVar23 = 0;
  if ((flags & 0x400) == 0) {
    iVar23 = iVar4;
  }
  if (pvVar3 == (void *)0x1) {
LAB_08175d53:
    iVar4 = 1;
  }
  else {
    iVar4 = (int)pvVar3 + -2;
    if (iVar4 < 0) {
LAB_08175d80:
      tree = (void **)CRYPTO_malloc(0x18,"pcy_tree.c",0xdf);
      if (tree != (void **)0x0) {
        tree[5] = (void *)0x0;
        pvVar7 = CRYPTO_malloc((int)pvVar3 << 4,"pcy_tree.c",0xe5);
        *tree = pvVar7;
        tree[1] = (void *)0x0;
        tree[2] = (void *)0x0;
        tree[3] = (void *)0x0;
        tree[4] = (void *)0x0;
        if (pvVar7 == (void *)0x0) {
          CRYPTO_free(tree);
        }
        else {
          memset(pvVar7,0,(int)pvVar3 << 4);
          tree[1] = pvVar3;
          ppvVar21 = (void **)*tree;
          pAVar8 = OBJ_nid2obj(0x2ea);
          iVar16 = policy_data_new(0,pAVar8,0);
          if ((iVar16 == 0) || (iVar16 = level_add_node(ppvVar21,iVar16,0,tree), iVar16 == 0)) {
            sk_free((_STACK *)tree[3]);
            sk_pop_free((_STACK *)tree[4],exnode_free);
            ppXVar17 = (X509 **)*tree;
            iVar4 = 0;
            if (0 < (int)tree[1]) {
              do {
                if (*ppXVar17 != (X509 *)0x0) {
                  X509_free(*ppXVar17);
                }
                if (ppXVar17[1] != (X509 *)0x0) {
                  sk_pop_free((_STACK *)ppXVar17[1],policy_node_free);
                }
                if (ppXVar17[2] != (X509 *)0x0) {
                  policy_node_free(ppXVar17[2]);
                }
                iVar4 = iVar4 + 1;
                ppXVar17 = ppXVar17 + 4;
              } while (iVar4 < (int)tree[1]);
            }
          }
          else {
            if (-1 < iVar4) {
              do {
                pvVar3 = sk_value(&certs->stack,iVar4);
                piVar9 = (int *)policy_cache_set(pvVar3);
                CRYPTO_add_lock((int *)((int)pvVar3 + 0x10),1,3,"pcy_tree.c",0x101);
                ppvVar21[4] = pvVar3;
                if (*piVar9 == 0) {
                  ppvVar21[7] = (void *)((uint)ppvVar21[7] | 0x200);
                }
                uVar12 = *(uint *)((int)pvVar3 + 0x28);
                if (local_4c == 0) {
                  if (((uVar12 & 0x20) == 0) || (iVar4 == 0)) {
                    ppvVar21[7] = (void *)((uint)ppvVar21[7] | 0x200);
                    goto LAB_08175f04;
                  }
                  if (iVar23 == 0) goto LAB_08175e79;
LAB_08175f12:
                  iVar16 = piVar9[4];
                  if ((-1 < iVar16) && (iVar16 < iVar23)) {
                    iVar23 = iVar16;
                  }
                }
                else {
                  iVar16 = piVar9[2];
                  iVar18 = local_4c - (uint)((uVar12 & 0x20) == 0);
                  local_4c = iVar18;
                  if ((iVar16 < iVar18) && (local_4c = iVar16, iVar16 < 0)) {
                    local_4c = iVar18;
                  }
LAB_08175f04:
                  if (iVar23 != 0) {
                    iVar23 = iVar23 - (uint)((uVar12 & 0x20) == 0);
                    goto LAB_08175f12;
                  }
LAB_08175e79:
                  ppvVar21[7] = (void *)((uint)ppvVar21[7] | 0x400);
                  iVar23 = 0;
                }
                iVar4 = iVar4 + -1;
                ppvVar21 = ppvVar21 + 4;
              } while (iVar4 != -1);
            }
            if (iVar15 == 0) {
              *pexplicit_policy = 1;
            }
            puVar13 = (undefined4 *)*tree;
            pvVar3 = tree[1];
            if (1 < (int)pvVar3) {
              local_3c = 1;
              puVar22 = puVar13;
LAB_08175f68:
              puVar19 = puVar22 + 4;
              piVar9 = (int *)policy_cache_set(*puVar19);
              for (local_48 = 0; iVar4 = sk_num((_STACK *)piVar9[1]), local_48 < iVar4;
                  local_48 = local_48 + 1) {
                pvVar3 = sk_value((_STACK *)piVar9[1],local_48);
                bVar2 = false;
                for (iVar4 = 0; iVar15 = sk_num((_STACK *)puVar22[1]), iVar4 < iVar15;
                    iVar4 = iVar4 + 1) {
                  pvVar7 = sk_value((_STACK *)puVar22[1],iVar4);
                  iVar15 = policy_node_match(puVar22,pvVar7,*(undefined4 *)((int)pvVar3 + 4));
                  if (iVar15 != 0) {
                    iVar15 = level_add_node(puVar19,pvVar3,pvVar7,0);
                    if (iVar15 == 0) goto LAB_08175c38;
                    bVar2 = true;
                  }
                }
                if (((!bVar2) && (puVar22[2] != 0)) &&
                   (iVar4 = level_add_node(puVar19,pvVar3,puVar22[2],0), iVar4 == 0))
                goto LAB_08175c38;
              }
              uVar12 = puVar22[7];
              if ((uVar12 & 0x200) == 0) {
                for (local_50 = 0; iVar4 = sk_num((_STACK *)puVar22[1]), local_50 < iVar4;
                    local_50 = local_50 + 1) {
                  ppuVar10 = (uint **)sk_value((_STACK *)puVar22[1],local_50);
                  if (((*(byte *)((int)puVar22 + 0xd) & 4) == 0) && ((*(byte *)*ppuVar10 & 1) != 0))
                  {
                    p_Var14 = (_STACK *)(*ppuVar10)[3];
                    puVar11 = ppuVar10[2];
                    puVar6 = (uint *)sk_num(p_Var14);
                    if (puVar11 != puVar6) {
                      for (iVar4 = 0; iVar15 = sk_num(p_Var14), iVar4 < iVar15; iVar4 = iVar4 + 1) {
                        pvVar3 = sk_value(p_Var14,iVar4);
                        iVar15 = level_find_node(puVar19,ppuVar10,pvVar3);
                        if (iVar15 == 0) {
                          if (pvVar3 == (void *)0x0) {
                            pvVar3 = (void *)(*ppuVar10)[1];
                          }
                          puVar11 = (uint *)policy_data_new(0,pvVar3,**ppuVar10 & 0x10);
                          if (puVar11 == (uint *)0x0) goto LAB_08175c38;
                          uVar12 = *(uint *)(*piVar9 + 8);
                          *puVar11 = *puVar11 | 4;
                          puVar11[2] = uVar12;
                          iVar15 = level_add_node(puVar19,puVar11,ppuVar10,tree);
                          if (iVar15 == 0) {
                            policy_data_free(puVar11);
                            goto LAB_08175c38;
                          }
                        }
                      }
                    }
                  }
                  else if (ppuVar10[2] == (uint *)0x0) {
                    puVar11 = (uint *)policy_data_new(0,(*ppuVar10)[1],**ppuVar10 & 0x10);
                    if (puVar11 == (uint *)0x0) goto LAB_08175c38;
                    uVar12 = *(uint *)(*piVar9 + 8);
                    *puVar11 = *puVar11 | 4;
                    puVar11[2] = uVar12;
                    iVar4 = level_add_node(puVar19,puVar11,ppuVar10,tree);
                    if (iVar4 == 0) {
                      policy_data_free(puVar11);
                      goto LAB_08175c38;
                    }
                  }
                }
                if ((puVar22[2] != 0) &&
                   (iVar4 = level_add_node(puVar19,*piVar9,puVar22[2],0), iVar4 == 0))
                goto LAB_08175c38;
                uVar12 = puVar22[7];
              }
              puVar13 = puVar19;
              if ((uVar12 & 0x400) != 0) {
                p_Var14 = (_STACK *)puVar22[5];
                iVar4 = sk_num(p_Var14);
                iVar4 = iVar4 + -1;
                if (-1 < iVar4) {
                  do {
                    ptr = (byte **)sk_value(p_Var14,iVar4);
                    if ((**ptr & 3) != 0) {
                      *(int *)(ptr[1] + 8) = *(int *)(ptr[1] + 8) + -1;
                      CRYPTO_free(ptr);
                      sk_delete(p_Var14,iVar4);
                    }
                    iVar4 = iVar4 + -1;
                  } while (iVar4 != -1);
                }
              }
              do {
                puVar22 = puVar13;
                puVar13 = puVar22 + -4;
                p_Var14 = (_STACK *)puVar22[-3];
                iVar15 = sk_num(p_Var14);
                iVar4 = iVar15 + -1;
                if (-1 < iVar15 + -1) {
                  do {
                    while (pvVar3 = sk_value(p_Var14,iVar4), *(int *)((int)pvVar3 + 8) != 0) {
                      iVar4 = iVar4 + -1;
                      if (iVar4 == -1) goto LAB_081761b8;
                    }
                    piVar9 = (int *)(*(int *)((int)pvVar3 + 4) + 8);
                    *piVar9 = *piVar9 + -1;
                    CRYPTO_free(pvVar3);
                    iVar15 = iVar4 + -1;
                    sk_delete(p_Var14,iVar4);
                    iVar4 = iVar15;
                  } while (iVar15 != -1);
                }
LAB_081761b8:
                pvVar3 = (void *)puVar22[-2];
                if ((pvVar3 != (void *)0x0) && (*(int *)((int)pvVar3 + 8) == 0)) {
                  if (*(int *)((int)pvVar3 + 4) != 0) {
                    piVar9 = (int *)(*(int *)((int)pvVar3 + 4) + 8);
                    *piVar9 = *piVar9 + -1;
                  }
                  CRYPTO_free(pvVar3);
                  puVar22[-2] = 0;
                }
              } while (puVar13 != (undefined4 *)*tree);
              if (puVar22[-2] != 0) goto code_r0x081761fb;
              sk_free((_STACK *)tree[3]);
              sk_pop_free((_STACK *)tree[4],exnode_free);
              ppXVar17 = (X509 **)*tree;
              iVar4 = 0;
              if (0 < (int)tree[1]) {
                do {
                  if (*ppXVar17 != (X509 *)0x0) {
                    X509_free(*ppXVar17);
                  }
                  if (ppXVar17[1] != (X509 *)0x0) {
                    sk_pop_free((_STACK *)ppXVar17[1],policy_node_free);
                  }
                  if (ppXVar17[2] != (X509 *)0x0) {
                    policy_node_free(ppXVar17[2]);
                  }
                  iVar4 = iVar4 + 1;
                  ppXVar17 = ppXVar17 + 4;
                } while (iVar4 < (int)tree[1]);
              }
              if ((_STACK *)tree[2] != (_STACK *)0x0) {
                sk_pop_free((_STACK *)tree[2],policy_data_free);
              }
              CRYPTO_free(*tree);
              CRYPTO_free(tree);
              if (*pexplicit_policy != 0) goto LAB_08176413;
              goto LAB_08175d53;
            }
LAB_08176216:
            pvVar7 = (void *)puVar13[((int)pvVar3 + 0xfffffff) * 4 + 2];
            if (pvVar7 == (void *)0x0) {
              pp_Var20 = (_STACK **)(tree + 3);
              if ((1 < (int)pvVar3) && (iVar4 = puVar13[2], iVar4 != 0)) {
LAB_0817626f:
                local_50 = 1;
                do {
                  for (iVar15 = 0; iVar23 = sk_num((_STACK *)puVar13[5]), iVar15 < iVar23;
                      iVar15 = iVar15 + 1) {
                    pvVar3 = sk_value((_STACK *)puVar13[5],iVar15);
                    if (*(int *)((int)pvVar3 + 4) == iVar4) {
                      if (*pp_Var20 == (_STACK *)0x0) {
                        p_Var14 = (_STACK *)policy_node_cmp_new();
                        *pp_Var20 = p_Var14;
                        if (p_Var14 == (_STACK *)0x0) goto LAB_08175c38;
                      }
                      else {
                        iVar23 = sk_find(*pp_Var20,pvVar3);
                        if (iVar23 != -1) goto LAB_08176280;
                        p_Var14 = *pp_Var20;
                      }
                      iVar23 = sk_push(p_Var14,pvVar3);
                      if (iVar23 == 0) goto LAB_08175c38;
                    }
LAB_08176280:
                  }
                  local_50 = local_50 + 1;
                } while ((local_50 < (int)tree[1]) &&
                        (iVar4 = puVar13[6], puVar13 = puVar13 + 4, iVar4 != 0));
              }
              if (pp_Var20 == &local_24) {
LAB_08176611:
                p_Var14 = local_24;
                iVar4 = sk_num(&policy_oids->stack);
                if (0 < iVar4) {
                  iVar4 = 2;
LAB_08176470:
                  ppuVar10 = *(uint ***)((int)*tree + ((int)tree[1] + 0xfffffff) * 0x10 + 8);
                  for (iVar15 = 0; iVar23 = sk_num(&policy_oids->stack), iVar15 < iVar23;
                      iVar15 = iVar15 + 1) {
                    pAVar8 = (ASN1_OBJECT *)sk_value(&policy_oids->stack,iVar15);
                    iVar23 = OBJ_obj2nid(pAVar8);
                    if (iVar23 == 0x2ea) {
                      tree[5] = (void *)((uint)tree[5] | 2);
                      goto LAB_08175d0f;
                    }
                  }
                  for (iVar15 = 0; iVar23 = sk_num(&policy_oids->stack), iVar15 < iVar23;
                      iVar15 = iVar15 + 1) {
                    pvVar7 = sk_value(&policy_oids->stack,iVar15);
                    pvVar3 = (void *)tree_find_sk(p_Var14,pvVar7);
                    if (pvVar3 == (void *)0x0) {
                      if (ppuVar10 != (uint **)0x0) {
                        puVar13 = (undefined4 *)policy_data_new(0,pvVar7,**ppuVar10 & 0x10);
                        if (puVar13 != (undefined4 *)0x0) {
                          uVar12 = (*ppuVar10)[2];
                          *puVar13 = 0xc;
                          puVar13[2] = uVar12;
                          pvVar3 = (void *)level_add_node(0,puVar13,ppuVar10[1],tree);
                          st = (_STACK *)tree[4];
                          goto joined_r0x081764d9;
                        }
                        goto LAB_08175c38;
                      }
                    }
                    else {
                      st = (_STACK *)tree[4];
joined_r0x081764d9:
                      if (st == (_STACK *)0x0) {
                        st = sk_new_null();
                        tree[4] = st;
                        if (st == (_STACK *)0x0) break;
                      }
                      iVar23 = sk_push(st,pvVar3);
                      if (iVar23 == 0) goto LAB_08175c38;
                    }
                  }
LAB_08175d0f:
                  if (iVar4 != 2) goto LAB_08175d20;
                }
                sk_free(p_Var14);
              }
              else {
                p_Var14 = (_STACK *)tree[3];
                local_24 = p_Var14;
                iVar4 = sk_num(&policy_oids->stack);
                if (0 < iVar4) {
                  iVar4 = 1;
                  goto LAB_08176470;
                }
              }
LAB_08175d20:
              *ptree = (X509_POLICY_TREE *)tree;
              if (*pexplicit_policy != 0) {
                p_Var14 = (_STACK *)X509_policy_tree_get0_user_policies((X509_POLICY_TREE *)tree);
                iVar4 = sk_num(p_Var14);
                if (iVar4 < 1) {
LAB_08176413:
                  iVar4 = -2;
                  goto LAB_08175cee;
                }
              }
              goto LAB_08175d53;
            }
            if ((_STACK *)tree[3] != (_STACK *)0x0) {
              iVar4 = sk_find((_STACK *)tree[3],pvVar7);
              if (iVar4 == -1) {
                p_Var14 = (_STACK *)tree[3];
                goto LAB_081765f7;
              }
LAB_08176250:
              puVar13 = (undefined4 *)*tree;
              if ((1 < (int)tree[1]) && (iVar4 = puVar13[2], iVar4 != 0)) {
                pp_Var20 = &local_24;
                goto LAB_0817626f;
              }
              goto LAB_08176611;
            }
            p_Var14 = (_STACK *)policy_node_cmp_new();
            tree[3] = p_Var14;
            if (p_Var14 != (_STACK *)0x0) {
LAB_081765f7:
              iVar4 = sk_push(p_Var14,pvVar7);
              if (iVar4 != 0) goto LAB_08176250;
LAB_08175c38:
              p_Var14 = (_STACK *)tree[3];
            }
            sk_free(p_Var14);
            sk_pop_free((_STACK *)tree[4],exnode_free);
            ppXVar17 = (X509 **)*tree;
            iVar4 = 0;
            if (0 < (int)tree[1]) {
              do {
                if (*ppXVar17 != (X509 *)0x0) {
                  X509_free(*ppXVar17);
                }
                if (ppXVar17[1] != (X509 *)0x0) {
                  sk_pop_free((_STACK *)ppXVar17[1],policy_node_free);
                }
                if (ppXVar17[2] != (X509 *)0x0) {
                  policy_node_free(ppXVar17[2]);
                }
                iVar4 = iVar4 + 1;
                ppXVar17 = ppXVar17 + 4;
              } while (iVar4 < (int)tree[1]);
            }
          }
          if ((_STACK *)tree[2] != (_STACK *)0x0) {
            sk_pop_free((_STACK *)tree[2],policy_data_free);
          }
          CRYPTO_free(*tree);
          CRYPTO_free(tree);
        }
      }
    }
    else {
      iVar18 = 1;
      iVar16 = iVar4;
      do {
        while( true ) {
          x = (X509 *)sk_value(&certs->stack,iVar16);
          X509_check_purpose(x,-1,-1);
          iVar5 = policy_cache_set(x);
          if (iVar5 == 0) goto LAB_08175cec;
          if ((x->ex_flags & 0x800) == 0) {
            if ((iVar18 == 1) && (*(int *)(iVar5 + 4) == 0)) {
              iVar18 = 2;
            }
          }
          else {
            iVar18 = -1;
          }
          iVar1 = iVar15;
          if (0 < iVar15) break;
LAB_08175ae0:
          iVar15 = iVar1;
          iVar16 = iVar16 + -1;
          if (iVar16 == -1) goto LAB_08175b30;
        }
        iVar1 = *(int *)(iVar5 + 0xc);
        iVar15 = iVar15 - (uint)((x->ex_flags & 0x20) == 0);
        if ((iVar1 != -1) && (iVar1 < iVar15)) goto LAB_08175ae0;
        iVar16 = iVar16 + -1;
      } while (iVar16 != -1);
LAB_08175b30:
      if (iVar18 == 1) goto LAB_08175d80;
      if ((iVar18 == 2) && (iVar15 == 0)) {
        *pexplicit_policy = 1;
        iVar4 = -2;
        goto LAB_08175cee;
      }
      if (iVar18 == 1) goto LAB_08175d53;
      iVar4 = 1;
      if (iVar18 == 2) goto LAB_08175cee;
      if (iVar18 != 0) {
        iVar4 = -1;
        goto LAB_08175cee;
      }
    }
LAB_08175cec:
    iVar4 = 0;
  }
LAB_08175cee:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
code_r0x081761fb:
  local_3c = local_3c + 1;
  pvVar3 = tree[1];
  puVar22 = puVar19;
  if ((int)pvVar3 <= local_3c) goto LAB_08176216;
  goto LAB_08175f68;
}

