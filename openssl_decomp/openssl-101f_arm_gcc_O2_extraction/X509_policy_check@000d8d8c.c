
int X509_policy_check(X509_POLICY_TREE **ptree,int *pexplicit_policy,stack_st_X509 *certs,
                     stack_st_ASN1_OBJECT *policy_oids,uint flags)

{
  void *pvVar1;
  X509 *x;
  int iVar2;
  _STACK *p_Var3;
  void **tree;
  void *pvVar4;
  ASN1_OBJECT *pAVar5;
  int *piVar6;
  uint **ppuVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  _STACK *st;
  int iVar12;
  X509 **ppXVar13;
  void *pvVar14;
  int iVar15;
  uint uVar16;
  _STACK **pp_Var17;
  int iVar18;
  int iVar19;
  void *pvVar20;
  int iVar21;
  bool bVar22;
  int local_60;
  int local_5c;
  int local_50;
  _STACK *local_2c [2];
  
  iVar12 = 0;
  *ptree = (X509_POLICY_TREE *)0x0;
  *pexplicit_policy = 0;
  local_2c[0] = (_STACK *)0x0;
  pvVar1 = (void *)sk_num(&certs->stack);
  if (-1 < (int)(flags << 0x17)) {
    iVar12 = (int)pvVar1 + 1;
  }
  if ((int)(flags << 0x16) < 0) {
    local_60 = 0;
  }
  else {
    local_60 = (int)pvVar1 + 1;
  }
  if ((int)(flags << 0x15) < 0) {
    iVar15 = 0;
  }
  else {
    iVar15 = (int)pvVar1 + 1;
  }
  if (pvVar1 == (void *)0x1) {
    return 1;
  }
  iVar18 = (int)pvVar1 + -2;
  if (-1 < iVar18) {
    iVar21 = 1;
    iVar19 = iVar18;
    do {
      x = (X509 *)sk_value(&certs->stack,iVar19);
      X509_check_purpose(x,-1,-1);
      iVar2 = policy_cache_set(x);
      if (iVar2 == 0) {
        return 0;
      }
      if ((int)(x->ex_flags << 0x14) < 0) {
        iVar21 = -1;
      }
      else if ((iVar21 == 1) && (*(int *)(iVar2 + 4) == 0)) {
        iVar21 = 2;
      }
      if (0 < iVar12) {
        iVar2 = *(int *)(iVar2 + 0xc);
        if (-1 < (int)(x->ex_flags << 0x1a)) {
          iVar12 = iVar12 + -1;
        }
        if ((iVar2 != -1) && (iVar2 <= iVar12)) {
          iVar12 = iVar2;
        }
      }
      bVar22 = iVar19 != 0;
      iVar19 = iVar19 + -1;
    } while (bVar22);
    if (iVar21 != 1) {
      if (iVar12 == 0 && iVar21 == 2) {
        *pexplicit_policy = 1;
        return -2;
      }
      if (iVar21 != 2) {
        if (iVar21 == 0) {
          return 0;
        }
        return iVar19;
      }
      return 1;
    }
  }
  tree = (void **)CRYPTO_malloc(0x18,"pcy_tree.c",0xde);
  if (tree == (void **)0x0) {
    return 0;
  }
  tree[5] = (void *)0x0;
  pvVar4 = CRYPTO_malloc((int)pvVar1 << 4,"pcy_tree.c",0xe4);
  tree[1] = (void *)0x0;
  tree[2] = (void *)0x0;
  tree[3] = (void *)0x0;
  tree[4] = (void *)0x0;
  *tree = pvVar4;
  if (pvVar4 == (void *)0x0) {
    CRYPTO_free(tree);
    return 0;
  }
  memset(pvVar4,0,(int)pvVar1 << 4);
  tree[1] = pvVar1;
  pvVar1 = *tree;
  pAVar5 = OBJ_nid2obj(0x2ea);
  iVar19 = policy_data_new(0,pAVar5,0);
  if ((iVar19 == 0) || (iVar19 = level_add_node(pvVar1,iVar19,0,tree), iVar19 == 0)) {
    sk_free((_STACK *)tree[3]);
    sk_pop_free((_STACK *)tree[4],exnode_free + 1);
    if (0 < (int)tree[1]) {
      iVar12 = 0;
      ppXVar13 = (X509 **)*tree;
      do {
        iVar12 = iVar12 + 1;
        if (*ppXVar13 != (X509 *)0x0) {
          X509_free(*ppXVar13);
        }
        if (ppXVar13[1] != (X509 *)0x0) {
          sk_pop_free((_STACK *)ppXVar13[1],policy_node_free);
        }
        if (ppXVar13[2] != (X509 *)0x0) {
          policy_node_free(ppXVar13[2]);
        }
        ppXVar13 = ppXVar13 + 4;
      } while (iVar12 < (int)tree[1]);
    }
    p_Var3 = (_STACK *)tree[2];
    goto joined_r0x000d8f42;
  }
  if (-1 < iVar18) {
    do {
      pvVar4 = sk_value(&certs->stack,iVar18);
      piVar6 = (int *)policy_cache_set();
      CRYPTO_add_lock((int *)((int)pvVar4 + 0x10),1,3,"pcy_tree.c",0x102);
      iVar19 = *piVar6;
      *(void **)((int)pvVar1 + 0x10) = pvVar4;
      if (iVar19 == 0) {
        *(uint *)((int)pvVar1 + 0x1c) = *(uint *)((int)pvVar1 + 0x1c) | 0x200;
      }
      uVar11 = *(uint *)((int)pvVar4 + 0x28);
      if (local_60 == 0) {
        if (((uVar11 & 0x20) == 0) || (iVar18 == 0)) {
          *(uint *)((int)pvVar1 + 0x1c) = *(uint *)((int)pvVar1 + 0x1c) | 0x200;
          goto LAB_000d9102;
        }
        if (iVar15 == 0) goto LAB_000d9094;
LAB_000d910a:
        iVar19 = piVar6[4];
        if ((-1 < iVar19) && (iVar19 <= iVar15)) {
          iVar15 = iVar19;
        }
      }
      else {
        iVar19 = piVar6[2];
        if ((uVar11 & 0x20) == 0) {
          local_60 = local_60 + -1;
        }
        if ((-1 < iVar19) && (iVar19 <= local_60)) {
          local_60 = iVar19;
        }
LAB_000d9102:
        if (iVar15 != 0) {
          if ((uVar11 & 0x20) == 0) {
            iVar15 = iVar15 + -1;
          }
          goto LAB_000d910a;
        }
LAB_000d9094:
        *(uint *)((int)pvVar1 + 0x1c) = *(uint *)((int)pvVar1 + 0x1c) | 0x400;
        iVar15 = 0;
      }
      iVar18 = iVar18 + -1;
      pvVar1 = (void *)((int)pvVar1 + 0x10);
    } while (iVar18 != -1);
  }
  if (iVar12 == 0) {
    *pexplicit_policy = 1;
  }
  else if (tree == (void **)0x0) {
    return 1;
  }
  pvVar4 = tree[1];
  pvVar1 = *tree;
  if (1 < (int)pvVar4) {
    local_5c = (int)pvVar1 + -0x10;
    local_50 = 1;
    pvVar14 = pvVar1;
    do {
      pvVar20 = (void *)((int)pvVar14 + 0x10);
      piVar6 = (int *)policy_cache_set(*(undefined4 *)((int)pvVar14 + 0x10));
      iVar15 = 0;
      iVar12 = sk_num((_STACK *)piVar6[1]);
      if (0 < iVar12) {
        do {
          bVar22 = false;
          pvVar1 = sk_value((_STACK *)piVar6[1],iVar15);
          iVar12 = 0;
          while( true ) {
            iVar18 = sk_num(*(_STACK **)(local_5c + 0x14));
            iVar19 = iVar12 + 1;
            if (iVar18 <= iVar12) break;
            pvVar4 = sk_value(*(_STACK **)(local_5c + 0x14),iVar12);
            iVar18 = policy_node_match(pvVar14,pvVar4,*(undefined4 *)((int)pvVar1 + 4));
            iVar12 = iVar19;
            if (iVar18 != 0) {
              iVar18 = level_add_node(pvVar20,pvVar1,pvVar4,0);
              bVar22 = true;
              if (iVar18 == 0) goto LAB_000d8ed4;
            }
          }
          if (((!bVar22) && (*(int *)(local_5c + 0x18) != 0)) &&
             (iVar12 = level_add_node(pvVar20,pvVar1,*(int *)(local_5c + 0x18),0), iVar12 == 0))
          goto LAB_000d8ed4;
          iVar15 = iVar15 + 1;
          iVar12 = sk_num((_STACK *)piVar6[1]);
        } while (iVar15 < iVar12);
      }
      uVar11 = *(uint *)((int)pvVar14 + 0x1c);
      uVar16 = uVar11 & 0x200;
      if (uVar16 == 0) {
        iVar12 = sk_num(*(_STACK **)(local_5c + 0x14));
        if (0 < iVar12) {
          do {
            ppuVar7 = (uint **)sk_value(*(_STACK **)(local_5c + 0x14),uVar16);
            uVar11 = *(uint *)((int)pvVar14 + 0xc) & 0x400;
            if ((uVar11 == 0) && ((int)(**ppuVar7 << 0x1f) < 0)) {
              p_Var3 = (_STACK *)(*ppuVar7)[3];
              puVar10 = ppuVar7[2];
              puVar9 = (uint *)sk_num(p_Var3);
              if (puVar10 != puVar9) {
                for (; iVar12 = sk_num(p_Var3), (int)uVar11 < iVar12; uVar11 = uVar11 + 1) {
                  pvVar1 = sk_value(p_Var3,uVar11);
                  iVar12 = level_find_node(pvVar20,ppuVar7,pvVar1);
                  if (iVar12 == 0) {
                    if (pvVar1 == (void *)0x0) {
                      pvVar1 = (void *)(*ppuVar7)[1];
                    }
                    puVar9 = (uint *)policy_data_new(0,pvVar1,**ppuVar7 & 0x10);
                    if (puVar9 == (uint *)0x0) goto LAB_000d8ed4;
                    puVar9[2] = *(uint *)(*piVar6 + 8);
                    *puVar9 = *puVar9 | 4;
                    iVar12 = level_add_node(pvVar20,puVar9,ppuVar7,tree);
                    if (iVar12 == 0) {
                      policy_data_free(puVar9);
                      goto LAB_000d8ed4;
                    }
                  }
                }
              }
            }
            else if (ppuVar7[2] == (uint *)0x0) {
              puVar9 = (uint *)policy_data_new(0,(*ppuVar7)[1],**ppuVar7 & 0x10);
              if (puVar9 == (uint *)0x0) goto LAB_000d8ed4;
              uVar11 = *(uint *)(*piVar6 + 8);
              *puVar9 = *puVar9 | 4;
              puVar9[2] = uVar11;
              iVar12 = level_add_node(pvVar20,puVar9,ppuVar7,tree);
              if (iVar12 == 0) {
                policy_data_free(puVar9);
                goto LAB_000d8ed4;
              }
            }
            uVar16 = uVar16 + 1;
            iVar12 = sk_num(*(_STACK **)(local_5c + 0x14));
          } while ((int)uVar16 < iVar12);
        }
        if ((*(int *)(local_5c + 0x18) != 0) &&
           (iVar12 = level_add_node(pvVar20,*piVar6,*(int *)(local_5c + 0x18),0), iVar12 == 0))
        goto LAB_000d8ed4;
        uVar11 = *(uint *)((int)pvVar14 + 0x1c);
      }
      p_Var3 = *(_STACK **)((int)pvVar14 + 0x14);
      pvVar4 = pvVar20;
      if ((int)(uVar11 << 0x15) < 0) {
        iVar12 = sk_num(p_Var3);
        iVar12 = iVar12 + -1;
        if (-1 < iVar12) {
          do {
            ppuVar7 = (uint **)sk_value(p_Var3,iVar12);
            if ((**ppuVar7 & 3) != 0) {
              ppuVar7[1][2] = ppuVar7[1][2] - 1;
              CRYPTO_free(ppuVar7);
              sk_delete(p_Var3,iVar12);
            }
            bVar22 = iVar12 != 0;
            iVar12 = iVar12 + -1;
          } while (bVar22);
        }
      }
      do {
        pvVar14 = pvVar4;
        p_Var3 = *(_STACK **)((int)pvVar14 + -0xc);
        iVar12 = sk_num(p_Var3);
        iVar12 = iVar12 + -1;
        if (-1 < iVar12) {
          do {
            while (pvVar1 = sk_value(p_Var3,iVar12), *(int *)((int)pvVar1 + 8) == 0) {
              *(int *)(*(int *)((int)pvVar1 + 4) + 8) = *(int *)(*(int *)((int)pvVar1 + 4) + 8) + -1
              ;
              CRYPTO_free(pvVar1);
              sk_delete(p_Var3,iVar12);
              bVar22 = iVar12 == 0;
              iVar12 = iVar12 + -1;
              if (bVar22) goto LAB_000d92ee;
            }
            bVar22 = iVar12 != 0;
            iVar12 = iVar12 + -1;
          } while (bVar22);
        }
LAB_000d92ee:
        pvVar1 = *(void **)((int)pvVar14 + -8);
        if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 8) == 0)) {
          iVar12 = *(int *)((int)pvVar1 + 4);
          if (iVar12 != 0) {
            *(int *)(iVar12 + 8) = *(int *)(iVar12 + 8) + -1;
          }
          CRYPTO_free(pvVar1);
          *(undefined4 *)((int)pvVar14 + -8) = 0;
        }
        pvVar1 = *tree;
        pvVar4 = (void *)((int)pvVar14 + -0x10);
      } while ((void *)((int)pvVar14 + -0x10) != pvVar1);
      iVar12 = *(int *)((int)pvVar14 + -8);
      if (iVar12 == 0) {
        sk_free((_STACK *)tree[3]);
        sk_pop_free((_STACK *)tree[4],exnode_free + 1);
        ppXVar13 = (X509 **)*tree;
        if (0 < (int)tree[1]) {
          do {
            iVar12 = iVar12 + 1;
            if (*ppXVar13 != (X509 *)0x0) {
              X509_free(*ppXVar13);
            }
            if (ppXVar13[1] != (X509 *)0x0) {
              sk_pop_free((_STACK *)ppXVar13[1],policy_node_free);
            }
            if (ppXVar13[2] != (X509 *)0x0) {
              policy_node_free(ppXVar13[2]);
            }
            ppXVar13 = ppXVar13 + 4;
          } while (iVar12 < (int)tree[1]);
        }
        if ((_STACK *)tree[2] != (_STACK *)0x0) {
          sk_pop_free((_STACK *)tree[2],policy_data_free);
        }
        CRYPTO_free(*tree);
        CRYPTO_free(tree);
        if (*pexplicit_policy != 0) {
          return -2;
        }
        return 1;
      }
      pvVar4 = tree[1];
      local_50 = local_50 + 1;
      local_5c = local_5c + 0x10;
      pvVar14 = pvVar20;
    } while (local_50 < (int)pvVar4);
  }
  pvVar14 = *(void **)((int)pvVar1 + (int)pvVar4 * 0x10 + -8);
  if (pvVar14 == (void *)0x0) {
    pp_Var17 = (_STACK **)(tree + 3);
    goto LAB_000d94a2;
  }
  if ((_STACK *)tree[3] == (_STACK *)0x0) {
    p_Var3 = (_STACK *)policy_node_cmp_new();
    tree[3] = p_Var3;
    if (p_Var3 == (_STACK *)0x0) goto LAB_000d8ed8;
LAB_000d9630:
    iVar12 = sk_push(p_Var3,pvVar14);
    if (iVar12 == 0) goto LAB_000d8ed4;
  }
  else {
    iVar12 = sk_find((_STACK *)tree[3],pvVar14);
    if (iVar12 == -1) {
      p_Var3 = (_STACK *)tree[3];
      goto LAB_000d9630;
    }
  }
  pvVar1 = *tree;
  pp_Var17 = local_2c;
  pvVar4 = tree[1];
LAB_000d94a2:
  if ((1 < (int)pvVar4) && (iVar12 = *(int *)((int)pvVar1 + 8), iVar12 != 0)) {
    iVar15 = 1;
LAB_000d94b4:
    iVar18 = 0;
LAB_000d94b6:
    do {
      iVar19 = sk_num(*(_STACK **)((int)pvVar1 + 0x14));
      iVar21 = iVar18 + 1;
      if (iVar19 <= iVar18) goto LAB_000d94f6;
      pvVar4 = sk_value(*(_STACK **)((int)pvVar1 + 0x14),iVar18);
      iVar18 = iVar21;
      if (iVar12 == *(int *)((int)pvVar4 + 4)) {
        if (*pp_Var17 == (_STACK *)0x0) {
          p_Var3 = (_STACK *)policy_node_cmp_new();
          *pp_Var17 = p_Var3;
          if (p_Var3 == (_STACK *)0x0) goto LAB_000d8ed4;
        }
        else {
          iVar19 = sk_find(*pp_Var17,pvVar4);
          if (iVar19 != -1) goto LAB_000d94b6;
          p_Var3 = *pp_Var17;
        }
        iVar19 = sk_push(p_Var3,pvVar4);
        if (iVar19 == 0) goto LAB_000d8ed4;
      }
    } while( true );
  }
LAB_000d950a:
  if (pp_Var17 == local_2c) {
    iVar12 = 2;
  }
  else {
    iVar12 = 1;
    local_2c[0] = (_STACK *)tree[3];
  }
  p_Var3 = local_2c[0];
  iVar15 = sk_num(&policy_oids->stack);
  if (0 < iVar15) {
    ppuVar7 = *(uint ***)((int)*tree + (int)tree[1] * 0x10 + -8);
    iVar15 = 0;
    do {
      iVar18 = sk_num(&policy_oids->stack);
      if (iVar18 <= iVar15) {
        iVar15 = 0;
        goto LAB_000d9590;
      }
      pAVar5 = (ASN1_OBJECT *)sk_value(&policy_oids->stack,iVar15);
      iVar18 = OBJ_obj2nid(pAVar5);
      iVar15 = iVar15 + 1;
    } while (iVar18 != 0x2ea);
    tree[5] = (void *)((uint)tree[5] | 2);
  }
LAB_000d8f9a:
  if (iVar12 == 2) {
    sk_free(p_Var3);
  }
  iVar12 = *pexplicit_policy;
  *ptree = (X509_POLICY_TREE *)tree;
  if (iVar12 != 0) {
    p_Var3 = (_STACK *)X509_policy_tree_get0_user_policies((X509_POLICY_TREE *)tree);
    iVar12 = sk_num(p_Var3);
    if (iVar12 < 1) {
      return -2;
    }
    return 1;
  }
  return 1;
LAB_000d94f6:
  iVar15 = iVar15 + 1;
  if ((int)tree[1] <= iVar15) goto LAB_000d950a;
  iVar12 = *(int *)((int)pvVar1 + 0x18);
  pvVar1 = (void *)((int)pvVar1 + 0x10);
  if (iVar12 == 0) goto LAB_000d950a;
  goto LAB_000d94b4;
  while( true ) {
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      tree[4] = st;
      if (st == (_STACK *)0x0) goto LAB_000d8f9a;
    }
    iVar18 = sk_push(st,pvVar1);
    if (iVar18 == 0) break;
LAB_000d9590:
    iVar18 = sk_num(&policy_oids->stack);
    iVar19 = iVar15 + 1;
    if (iVar18 <= iVar15) goto LAB_000d8f9a;
    pvVar4 = sk_value(&policy_oids->stack,iVar15);
    pvVar1 = (void *)tree_find_sk(p_Var3,pvVar4);
    iVar15 = iVar19;
    if (pvVar1 == (void *)0x0) {
      if (ppuVar7 == (uint **)0x0) goto LAB_000d9590;
      puVar8 = (undefined4 *)policy_data_new(0,pvVar4,**ppuVar7 & 0x10);
      if (puVar8 == (undefined4 *)0x0) break;
      puVar9 = ppuVar7[1];
      uVar11 = (*ppuVar7)[2];
      *puVar8 = 0xc;
      puVar8[2] = uVar11;
      pvVar1 = (void *)level_add_node(0,puVar8,puVar9,tree);
      st = (_STACK *)tree[4];
    }
    else {
      st = (_STACK *)tree[4];
    }
  }
LAB_000d8ed4:
  p_Var3 = (_STACK *)tree[3];
LAB_000d8ed8:
  sk_free(p_Var3);
  sk_pop_free((_STACK *)tree[4],exnode_free + 1);
  if (0 < (int)tree[1]) {
    iVar12 = 0;
    ppXVar13 = (X509 **)*tree;
    do {
      iVar12 = iVar12 + 1;
      if (*ppXVar13 != (X509 *)0x0) {
        X509_free(*ppXVar13);
      }
      if (ppXVar13[1] != (X509 *)0x0) {
        sk_pop_free((_STACK *)ppXVar13[1],policy_node_free);
      }
      if (ppXVar13[2] != (X509 *)0x0) {
        policy_node_free(ppXVar13[2]);
      }
      ppXVar13 = ppXVar13 + 4;
    } while (iVar12 < (int)tree[1]);
  }
  p_Var3 = (_STACK *)tree[2];
joined_r0x000d8f42:
  if (p_Var3 != (_STACK *)0x0) {
    sk_pop_free(p_Var3,policy_data_free);
  }
  CRYPTO_free(*tree);
  CRYPTO_free(tree);
  return 0;
}

