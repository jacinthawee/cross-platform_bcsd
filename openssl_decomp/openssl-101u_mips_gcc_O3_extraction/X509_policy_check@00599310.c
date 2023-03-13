
int X509_policy_check(X509_POLICY_TREE **ptree,int *pexplicit_policy,stack_st_X509 *certs,
                     stack_st_ASN1_OBJECT *policy_oids,uint flags)

{
  int *piVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  int *piVar5;
  X509 *x;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  stack_st_X509_POLICY_NODE *psVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  uint *puVar13;
  uint *puVar14;
  int *piVar15;
  int iVar16;
  uint **ppuVar17;
  int **ppiVar18;
  int iVar19;
  int iVar20;
  int **unaff_s7;
  int iVar21;
  int local_48;
  int *local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  puVar3 = PTR_sk_num_006a6e2c;
  local_30 = (int *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  *ptree = (X509_POLICY_TREE *)0x0;
  *pexplicit_policy = 0;
  piVar5 = (int *)(*(code *)puVar3)(certs);
  if ((flags & 0x100) == 0) {
    iVar21 = (int)piVar5 + 1;
  }
  else {
    iVar21 = 0;
  }
  iVar19 = 0;
  if ((flags & 0x200) == 0) {
    iVar19 = (int)piVar5 + 1;
  }
  if ((flags & 0x400) == 0) {
    iVar16 = (int)piVar5 + 1;
  }
  else {
    iVar16 = 0;
  }
  if (piVar5 == (int *)0x1) goto LAB_005994e0;
  ppiVar18 = (int **)((int)piVar5 + -2);
  iVar20 = 1;
  unaff_s7 = ppiVar18;
  if (-1 < (int)ppiVar18) {
    do {
      x = (X509 *)(*(code *)PTR_sk_value_006a6e24)(certs,unaff_s7);
      X509_check_purpose(x,-1,-1);
      iVar6 = policy_cache_set(x);
      if (iVar6 == 0) goto LAB_00599480;
      if ((x->ex_flags & 0x800) == 0) {
        if ((iVar20 == 1) && (*(int *)(iVar6 + 4) == 0)) {
          iVar20 = 2;
        }
      }
      else {
        iVar20 = -1;
      }
      if (0 < iVar21) {
        iVar6 = *(int *)(iVar6 + 0xc);
        if ((x->ex_flags & 0x20) == 0) {
          iVar21 = iVar21 + -1;
        }
        if ((iVar6 != -1) && (iVar6 < iVar21)) {
          iVar21 = iVar6;
        }
      }
      unaff_s7 = (int **)((int)unaff_s7 + -1);
    } while (unaff_s7 != (int **)0xffffffff);
    if (iVar20 != 1) {
      if (iVar20 == 2) {
        if (iVar21 != 0) goto LAB_005994e0;
        *pexplicit_policy = 1;
        iVar21 = -2;
        goto LAB_00599484;
      }
      if (iVar20 != 0) {
        if (iVar20 == 1) goto LAB_005994e0;
        iVar21 = -1;
        goto LAB_00599484;
      }
      goto LAB_00599480;
    }
  }
  unaff_s7 = (int **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"pcy_tree.c",0xdf);
  puVar3 = PTR_CRYPTO_malloc_006a7008;
  if (unaff_s7 != (int **)0x0) {
    unaff_s7[5] = (int *)0x0;
    piVar12 = (int *)(*(code *)puVar3)((int)piVar5 << 4,"pcy_tree.c",0xe5);
    unaff_s7[1] = (int *)0x0;
    unaff_s7[2] = (int *)0x0;
    *unaff_s7 = piVar12;
    unaff_s7[3] = (int *)0x0;
    unaff_s7[4] = (int *)0x0;
    if (piVar12 != (int *)0x0) {
      (*(code *)PTR_memset_006a99f4)(piVar12,0,(int)piVar5 << 4);
      puVar3 = PTR_OBJ_nid2obj_006a7140;
      piVar12 = *unaff_s7;
      unaff_s7[1] = piVar5;
      uVar7 = (*(code *)puVar3)(0x2ea);
      iVar20 = policy_data_new(0,uVar7,0);
      if ((iVar20 == 0) ||
         (iVar20 = (*(code *)PTR_level_add_node_006a90c0)(piVar12,iVar20,0,unaff_s7), iVar20 == 0))
      {
        certs = (stack_st_X509 *)0x0;
        (*(code *)PTR_sk_free_006a6e80)(unaff_s7[3]);
        (*(code *)PTR_sk_pop_free_006a7058)(unaff_s7[4],exnode_free);
        piVar5 = *unaff_s7;
        if ((int)unaff_s7[1] < 1) goto LAB_00599d88;
        do {
          if (*piVar5 != 0) {
            (*(code *)PTR_X509_free_006a6e90)();
          }
          if (piVar5[1] != 0) {
            (*(code *)PTR_sk_pop_free_006a7058)(piVar5[1],PTR_policy_node_free_006a90b8);
          }
          if (piVar5[2] != 0) {
            (*(code *)PTR_policy_node_free_006a90b8)();
          }
          certs = (stack_st_X509 *)((int)&(certs->stack).num + 1);
          piVar5 = piVar5 + 4;
        } while ((int)certs < (int)unaff_s7[1]);
        piVar5 = unaff_s7[2];
        goto LAB_00599d8c;
      }
      if (-1 < (int)ppiVar18) {
        do {
          iVar20 = (*(code *)PTR_sk_value_006a6e24)(certs,ppiVar18);
          piVar5 = (int *)policy_cache_set(iVar20);
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar20 + 0x10,1,3,"pcy_tree.c",0x101);
          piVar12[4] = iVar20;
          if (*piVar5 == 0) {
            piVar12[7] = piVar12[7] | 0x200;
          }
          uVar11 = *(uint *)(iVar20 + 0x28);
          if (iVar19 == 0) {
            if (((uVar11 & 0x20) == 0) || (ppiVar18 == (int **)0x0)) {
              piVar12[7] = piVar12[7] | 0x200;
              goto LAB_005996bc;
            }
            if (iVar16 == 0) goto LAB_00599610;
LAB_005996c8:
            iVar20 = piVar5[4];
            if ((-1 < iVar20) && (iVar20 < iVar16)) {
              iVar16 = iVar20;
            }
          }
          else {
            iVar20 = piVar5[2];
            if ((uVar11 & 0x20) == 0) {
              iVar19 = iVar19 + -1;
            }
            if ((-1 < iVar20) && (iVar20 < iVar19)) {
              iVar19 = iVar20;
            }
LAB_005996bc:
            if (iVar16 != 0) {
              if ((uVar11 & 0x20) == 0) {
                iVar16 = iVar16 + -1;
              }
              goto LAB_005996c8;
            }
LAB_00599610:
            piVar12[7] = piVar12[7] | 0x400;
            iVar16 = 0;
          }
          ppiVar18 = (int **)((int)ppiVar18 + -1);
          piVar12 = piVar12 + 4;
        } while (ppiVar18 != (int **)0xffffffff);
      }
      if (iVar21 == 0) {
        *pexplicit_policy = 1;
      }
      piVar12 = unaff_s7[1];
      piVar5 = *unaff_s7;
      if (1 < (int)piVar12) {
        local_48 = 1;
        piVar1 = piVar5;
        do {
          piVar15 = piVar1 + 4;
          iVar19 = 0;
          piVar5 = (int *)policy_cache_set(*piVar15);
          iVar21 = (*(code *)PTR_sk_num_006a6e2c)(piVar5[1]);
          if (0 < iVar21) {
            do {
              iVar20 = 0;
              bVar2 = false;
              iVar21 = (*(code *)PTR_sk_value_006a6e24)(piVar5[1],iVar19);
              iVar16 = (*(code *)PTR_sk_num_006a6e2c)(piVar1[1]);
              if (0 < iVar16) {
                do {
                  uVar7 = (*(code *)PTR_sk_value_006a6e24)(piVar1[1],iVar20);
                  iVar16 = (*(code *)PTR_policy_node_match_006a90c4)
                                     (piVar1,uVar7,*(undefined4 *)(iVar21 + 4));
                  if (iVar16 != 0) {
                    iVar16 = (*(code *)PTR_level_add_node_006a90c0)(piVar15,iVar21,uVar7,0);
                    if (iVar16 == 0) goto LAB_00599cf0;
                    bVar2 = true;
                  }
                  iVar20 = iVar20 + 1;
                  iVar16 = (*(code *)PTR_sk_num_006a6e2c)(piVar1[1]);
                } while (iVar20 < iVar16);
              }
              if (((!bVar2) && (piVar1[2] != 0)) &&
                 (iVar21 = (*(code *)PTR_level_add_node_006a90c0)(piVar15,iVar21,piVar1[2],0),
                 iVar21 == 0)) goto LAB_00599cf0;
              iVar19 = iVar19 + 1;
              iVar21 = (*(code *)PTR_sk_num_006a6e2c)(piVar5[1]);
            } while (iVar19 < iVar21);
          }
          uVar11 = piVar1[7];
          if ((uVar11 & 0x200) == 0) {
            iVar19 = 0;
            iVar21 = (*(code *)PTR_sk_num_006a6e2c)(piVar1[1]);
            if (0 < iVar21) {
              do {
                ppuVar17 = (uint **)(*(code *)PTR_sk_value_006a6e24)(piVar1[1],iVar19);
                if (((piVar1[3] & 0x400U) == 0) && ((**ppuVar17 & 1) != 0)) {
                  uVar11 = (*ppuVar17)[3];
                  puVar14 = ppuVar17[2];
                  puVar13 = (uint *)(*(code *)PTR_sk_num_006a6e2c)(uVar11);
                  if (puVar14 != puVar13) {
                    for (iVar21 = 0; iVar16 = (*(code *)PTR_sk_num_006a6e2c)(uVar11),
                        iVar21 < iVar16; iVar21 = iVar21 + 1) {
                      uVar8 = (*(code *)PTR_sk_value_006a6e24)(uVar11,iVar21);
                      iVar16 = (*(code *)PTR_level_find_node_006a90cc)(piVar15,ppuVar17,uVar8);
                      if (iVar16 == 0) {
                        if (uVar8 == 0) {
                          uVar8 = (*ppuVar17)[1];
                        }
                        puVar13 = (uint *)policy_data_new(0,uVar8,**ppuVar17 & 0x10);
                        puVar3 = PTR_level_add_node_006a90c0;
                        if (puVar13 == (uint *)0x0) goto LAB_00599cf0;
                        uVar8 = *(uint *)(*piVar5 + 8);
                        *puVar13 = *puVar13 | 4;
                        puVar13[2] = uVar8;
                        iVar16 = (*(code *)puVar3)(piVar15,puVar13,ppuVar17,unaff_s7);
                        if (iVar16 == 0) {
                          policy_data_free(puVar13);
                          goto LAB_00599cf0;
                        }
                      }
                    }
                  }
                }
                else if (ppuVar17[2] == (uint *)0x0) {
                  puVar13 = (uint *)policy_data_new(0,(*ppuVar17)[1],**ppuVar17 & 0x10);
                  puVar3 = PTR_level_add_node_006a90c0;
                  if (puVar13 == (uint *)0x0) goto LAB_00599cf0;
                  uVar11 = *(uint *)(*piVar5 + 8);
                  *puVar13 = *puVar13 | 4;
                  puVar13[2] = uVar11;
                  iVar21 = (*(code *)puVar3)(piVar15,puVar13,ppuVar17,unaff_s7);
                  if (iVar21 == 0) {
                    policy_data_free(puVar13);
                    goto LAB_00599cf0;
                  }
                }
                iVar19 = iVar19 + 1;
                iVar21 = (*(code *)PTR_sk_num_006a6e2c)(piVar1[1]);
              } while (iVar19 < iVar21);
            }
            if ((piVar1[2] != 0) &&
               (iVar21 = (*(code *)PTR_level_add_node_006a90c0)(piVar15,*piVar5,piVar1[2],0),
               iVar21 == 0)) goto LAB_00599cf0;
            uVar11 = piVar1[7];
          }
          piVar5 = piVar15;
          if ((uVar11 & 0x400) != 0) {
            iVar19 = piVar1[5];
            iVar21 = (*(code *)PTR_sk_num_006a6e2c)(iVar19);
            iVar21 = iVar21 + -1;
            if (-1 < iVar21) {
              do {
                ppuVar17 = (uint **)(*(code *)PTR_sk_value_006a6e24)(iVar19,iVar21);
                puVar3 = PTR_CRYPTO_free_006a6e88;
                if ((**ppuVar17 & 3) != 0) {
                  ppuVar17[1][2] = ppuVar17[1][2] - 1;
                  (*(code *)puVar3)(ppuVar17);
                  (*(code *)PTR_sk_delete_006a7288)(iVar19,iVar21);
                }
                iVar21 = iVar21 + -1;
              } while (iVar21 != -1);
            }
          }
          do {
            piVar12 = piVar5;
            piVar5 = piVar12 + -4;
            iVar16 = piVar12[-3];
            iVar19 = (*(code *)PTR_sk_num_006a6e2c)(iVar16);
            iVar21 = iVar19 + -1;
            if (iVar19 + -1 < 0) {
              iVar21 = piVar12[-2];
            }
            else {
              do {
                while (iVar19 = (*(code *)PTR_sk_value_006a6e24)(iVar16,iVar21),
                      puVar3 = PTR_CRYPTO_free_006a6e88, *(int *)(iVar19 + 8) != 0) {
                  iVar21 = iVar21 + -1;
                  if (iVar21 == -1) goto LAB_0059998c;
                }
                *(int *)(*(int *)(iVar19 + 4) + 8) = *(int *)(*(int *)(iVar19 + 4) + 8) + -1;
                (*(code *)puVar3)(iVar19);
                iVar19 = iVar21 + -1;
                (*(code *)PTR_sk_delete_006a7288)(iVar16,iVar21);
                iVar21 = iVar19;
              } while (iVar19 != -1);
LAB_0059998c:
              iVar21 = piVar12[-2];
            }
            puVar3 = PTR_CRYPTO_free_006a6e88;
            if ((iVar21 != 0) && (*(int *)(iVar21 + 8) == 0)) {
              iVar21 = *(int *)(iVar21 + 4);
              if (iVar21 != 0) {
                *(int *)(iVar21 + 8) = *(int *)(iVar21 + 8) + -1;
              }
              (*(code *)puVar3)();
              piVar12[-2] = 0;
            }
          } while (piVar5 != *unaff_s7);
          if (piVar12[-2] == 0) {
            certs = (stack_st_X509 *)0x0;
            (*(code *)PTR_sk_free_006a6e80)(unaff_s7[3]);
            (*(code *)PTR_sk_pop_free_006a7058)(unaff_s7[4],exnode_free);
            piVar5 = *unaff_s7;
            if (0 < (int)unaff_s7[1]) {
              do {
                if (*piVar5 != 0) {
                  (*(code *)PTR_X509_free_006a6e90)();
                }
                if (piVar5[1] != 0) {
                  (*(code *)PTR_sk_pop_free_006a7058)(piVar5[1],PTR_policy_node_free_006a90b8);
                }
                if (piVar5[2] != 0) {
                  (*(code *)PTR_policy_node_free_006a90b8)();
                }
                certs = (stack_st_X509 *)((int)&(certs->stack).num + 1);
                piVar5 = piVar5 + 4;
              } while ((int)certs < (int)unaff_s7[1]);
            }
            if (unaff_s7[2] != (int *)0x0) {
              (*(code *)PTR_sk_pop_free_006a7058)(unaff_s7[2],PTR_policy_data_free_006a9098);
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(*unaff_s7);
            (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s7);
            if (*pexplicit_policy == 0) goto LAB_005994e0;
            goto LAB_00599fec;
          }
          piVar12 = unaff_s7[1];
          local_48 = local_48 + 1;
          piVar1 = piVar15;
        } while (local_48 < (int)piVar12);
      }
      certs = (stack_st_X509 *)piVar5[(int)piVar12 * 4 + -2];
      if (certs != (stack_st_X509 *)0x0) {
        if (unaff_s7[3] == (int *)0x0) goto LAB_0059a1e0;
        iVar21 = (*(code *)PTR_sk_find_006a8044)(unaff_s7[3],certs);
        if (iVar21 != -1) goto LAB_00599a38;
        piVar5 = unaff_s7[3];
        goto LAB_0059a1fc;
      }
      ppiVar18 = unaff_s7 + 3;
      if ((int)piVar12 < 2) goto LAB_00599ae0;
      iVar21 = piVar5[2];
      if (iVar21 == 0) goto LAB_00599ae0;
      goto LAB_00599a5c;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s7);
  }
LAB_00599480:
  do {
    iVar21 = 0;
LAB_00599484:
    if (local_2c == *(int *)puVar4) {
      return iVar21;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0059a1e0:
    piVar5 = (int *)(*(code *)PTR_policy_node_cmp_new_006a90d0)();
    unaff_s7[3] = piVar5;
    if (piVar5 == (int *)0x0) goto LAB_00599cf4;
LAB_0059a1fc:
    iVar21 = (*(code *)PTR_sk_push_006a6fa8)(piVar5,certs);
    if (iVar21 == 0) {
      piVar5 = unaff_s7[3];
      goto LAB_00599cf4;
    }
LAB_00599a38:
    piVar5 = *unaff_s7;
    if (1 < (int)unaff_s7[1]) {
      iVar21 = piVar5[2];
      ppiVar18 = &local_30;
      if (iVar21 == 0) goto LAB_0059a218;
LAB_00599a5c:
      iVar19 = 1;
      do {
        certs = (stack_st_X509 *)0x0;
        iVar16 = (*(code *)PTR_sk_num_006a6e2c)(piVar5[5]);
        if (0 < iVar16) {
          do {
            iVar16 = (*(code *)PTR_sk_value_006a6e24)(piVar5[5],certs);
            if (*(int *)(iVar16 + 4) == iVar21) {
              if (*ppiVar18 == (int *)0x0) {
                piVar12 = (int *)(*(code *)PTR_policy_node_cmp_new_006a90d0)();
                *ppiVar18 = piVar12;
                if (piVar12 == (int *)0x0) {
                  piVar5 = unaff_s7[3];
                  goto LAB_00599cf4;
                }
              }
              else {
                iVar20 = (*(code *)PTR_sk_find_006a8044)(*ppiVar18,iVar16);
                if (iVar20 != -1) goto LAB_00599aa0;
                piVar12 = *ppiVar18;
              }
              iVar16 = (*(code *)PTR_sk_push_006a6fa8)(piVar12,iVar16);
              if (iVar16 == 0) goto LAB_00599cf0;
            }
LAB_00599aa0:
            certs = (stack_st_X509 *)((int)&(certs->stack).num + 1);
            iVar16 = (*(code *)PTR_sk_num_006a6e2c)(piVar5[5]);
          } while ((int)certs < iVar16);
        }
        iVar19 = iVar19 + 1;
      } while ((iVar19 < (int)unaff_s7[1]) && (iVar21 = piVar5[6], piVar5 = piVar5 + 4, iVar21 != 0)
              );
LAB_00599ae0:
      iVar21 = 1;
      if (ppiVar18 == &local_30) goto LAB_0059a218;
      piVar5 = unaff_s7[3];
      local_30 = piVar5;
      iVar19 = (*(code *)PTR_sk_num_006a6e2c)(policy_oids);
      if (0 < iVar19) goto LAB_00599b04;
      goto LAB_0059a0f4;
    }
LAB_0059a218:
    piVar5 = local_30;
    iVar21 = (*(code *)PTR_sk_num_006a6e2c)(policy_oids);
    if (iVar21 < 1) goto LAB_0059a138;
    iVar21 = 2;
LAB_00599b04:
    certs = (stack_st_X509 *)0x2ea;
    ppuVar17 = (uint **)(*unaff_s7)[(int)unaff_s7[1] * 4 + -2];
    for (iVar19 = 0; iVar16 = (*(code *)PTR_sk_num_006a6e2c)(policy_oids), iVar19 < iVar16;
        iVar19 = iVar19 + 1) {
      uVar7 = (*(code *)PTR_sk_value_006a6e24)(policy_oids,iVar19);
      iVar16 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uVar7);
      if (iVar16 == 0x2ea) {
        unaff_s7[5] = (int *)((uint)unaff_s7[5] | 2);
        goto LAB_0059a0e8;
      }
    }
    certs = (stack_st_X509 *)0x0;
LAB_00599b70:
    iVar19 = (*(code *)PTR_sk_num_006a6e2c)(policy_oids);
    if (iVar19 <= (int)certs) break;
    uVar7 = (*(code *)PTR_sk_value_006a6e24)(policy_oids,certs);
    iVar19 = (*(code *)PTR_tree_find_sk_006a90c8)(piVar5,uVar7);
    if (iVar19 != 0) {
LAB_00599bbc:
      piVar12 = unaff_s7[4];
      if (piVar12 == (int *)0x0) {
        piVar12 = (int *)(*(code *)PTR_sk_new_null_006a6fa4)();
        unaff_s7[4] = piVar12;
        if (piVar12 == (int *)0x0) break;
      }
      iVar19 = (*(code *)PTR_sk_push_006a6fa8)(piVar12,iVar19);
      if (iVar19 == 0) goto LAB_00599cf0;
LAB_00599bdc:
      certs = (stack_st_X509 *)((int)&(certs->stack).num + 1);
      goto LAB_00599b70;
    }
    if (ppuVar17 == (uint **)0x0) goto LAB_00599bdc;
    puVar10 = (undefined4 *)policy_data_new(0,uVar7,**ppuVar17 & 0x10);
    puVar3 = PTR_level_add_node_006a90c0;
    if (puVar10 != (undefined4 *)0x0) {
      puVar13 = ppuVar17[1];
      uVar11 = (*ppuVar17)[2];
      *puVar10 = 0xc;
      puVar10[2] = uVar11;
      iVar19 = (*(code *)puVar3)(0,puVar10,puVar13,unaff_s7);
      goto LAB_00599bbc;
    }
LAB_00599cf0:
    piVar5 = unaff_s7[3];
LAB_00599cf4:
    certs = (stack_st_X509 *)0x0;
    (*(code *)PTR_sk_free_006a6e80)(piVar5);
    (*(code *)PTR_sk_pop_free_006a7058)(unaff_s7[4],exnode_free);
    piVar5 = *unaff_s7;
    if (0 < (int)unaff_s7[1]) {
      do {
        if (*piVar5 != 0) {
          (*(code *)PTR_X509_free_006a6e90)();
        }
        if (piVar5[1] != 0) {
          (*(code *)PTR_sk_pop_free_006a7058)(piVar5[1],PTR_policy_node_free_006a90b8);
        }
        if (piVar5[2] != 0) {
          (*(code *)PTR_policy_node_free_006a90b8)();
        }
        certs = (stack_st_X509 *)((int)&(certs->stack).num + 1);
        piVar5 = piVar5 + 4;
      } while ((int)certs < (int)unaff_s7[1]);
    }
LAB_00599d88:
    piVar5 = unaff_s7[2];
LAB_00599d8c:
    if (piVar5 != (int *)0x0) {
      (*(code *)PTR_sk_pop_free_006a7058)(piVar5,PTR_policy_data_free_006a9098);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(*unaff_s7);
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s7);
  } while( true );
LAB_0059a0e8:
  if (iVar21 == 2) {
LAB_0059a138:
    (*(code *)PTR_sk_free_006a6e80)(piVar5);
  }
LAB_0059a0f4:
  iVar21 = *pexplicit_policy;
  *ptree = (X509_POLICY_TREE *)unaff_s7;
  if (iVar21 == 0) {
LAB_005994e0:
    iVar21 = 1;
  }
  else {
    psVar9 = X509_policy_tree_get0_user_policies((X509_POLICY_TREE *)unaff_s7);
    iVar21 = (*(code *)PTR_sk_num_006a6e2c)(psVar9);
    if (iVar21 < 1) {
LAB_00599fec:
      iVar21 = -2;
    }
    else {
      iVar21 = 1;
    }
  }
  goto LAB_00599484;
}

