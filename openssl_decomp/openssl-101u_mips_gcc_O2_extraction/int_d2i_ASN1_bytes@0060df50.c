
/* WARNING: Type propagation algorithm not settling */

stack_st_OPENSSL_BLOCK *
int_d2i_ASN1_bytes(stack_st_OPENSSL_BLOCK **param_1,char *param_2,stack_st_OPENSSL_BLOCK *param_3,
                  stack_st_OPENSSL_BLOCK *param_4,stack_st_OPENSSL_BLOCK *param_5,int param_6,
                  int *param_7)

{
  undefined *puVar1;
  stack_st_OPENSSL_BLOCK *psVar2;
  uint uVar3;
  stack_st_OPENSSL_BLOCK *psVar4;
  stack_st_OPENSSL_BLOCK *psVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  stack_st_OPENSSL_BLOCK *psVar10;
  int **ppiVar11;
  int *piVar12;
  stack_st_OPENSSL_BLOCK *psVar13;
  stack_st_OPENSSL_BLOCK **ppsVar14;
  stack_st_OPENSSL_BLOCK **ppsVar15;
  undefined4 uVar16;
  char *pcVar17;
  stack_st_OPENSSL_BLOCK *psVar18;
  stack_st_OPENSSL_BLOCK *unaff_s0;
  stack_st_OPENSSL_BLOCK *unaff_s1;
  stack_st_OPENSSL_BLOCK *unaff_s3;
  stack_st_OPENSSL_BLOCK *unaff_s4;
  stack_st_OPENSSL_BLOCK *unaff_s5;
  stack_st_OPENSSL_BLOCK *psVar19;
  stack_st_OPENSSL_BLOCK *unaff_s6;
  stack_st_OPENSSL_BLOCK *unaff_s7;
  code *pcVar20;
  stack_st_OPENSSL_BLOCK *unaff_s8;
  int iStack_3a8;
  int iStack_3a4;
  undefined *puStack_39c;
  stack_st_OPENSSL_BLOCK *psStack_398;
  undefined *puStack_394;
  uchar **ppuStack_390;
  char *pcStack_38c;
  char *pcStack_388;
  code *pcStack_384;
  undefined4 uStack_370;
  undefined *puStack_368;
  stack_st_OPENSSL_BLOCK *psStack_35c;
  int *piStack_358;
  int iStack_354;
  stack_st_OPENSSL_BLOCK *psStack_350;
  code *pcStack_34c;
  stack_st_OPENSSL_BLOCK *psStack_328;
  int **ppiStack_324;
  undefined *puStack_31c;
  stack_st_OPENSSL_BLOCK *psStack_318;
  stack_st_OPENSSL_BLOCK **ppsStack_314;
  stack_st_OPENSSL_BLOCK *psStack_310;
  undefined *puStack_30c;
  stack_st_OPENSSL_BLOCK *psStack_308;
  stack_st_OPENSSL_BLOCK *psStack_304;
  stack_st_OPENSSL_BLOCK *psStack_300;
  code *pcStack_2fc;
  uchar *puStack_2c8;
  stack_st_OPENSSL_BLOCK *psStack_2c4;
  stack_st_OPENSSL_BLOCK *psStack_2c0;
  undefined4 uStack_2bc;
  stack_st_OPENSSL_BLOCK *psStack_2a8;
  undefined4 uStack_2a4;
  int *piStack_2a0;
  undefined *puStack_298;
  stack_st_OPENSSL_BLOCK *psStack_28c;
  stack_st_OPENSSL_BLOCK **ppsStack_288;
  stack_st_OPENSSL_BLOCK *psStack_284;
  uchar **ppuStack_280;
  stack_st_OPENSSL_BLOCK *psStack_27c;
  int *piStack_278;
  char *pcStack_274;
  stack_st_OPENSSL_BLOCK *psStack_270;
  undefined auStack_26c [8];
  undefined auStack_264 [4];
  stack_st_OPENSSL_BLOCK *psStack_260;
  undefined auStack_25c [8];
  undefined auStack_254 [8];
  char **ppcStack_24c;
  int iStack_248;
  _func_257 *p_Stack_244;
  _func_257 *p_Stack_240;
  stack_st_OPENSSL_BLOCK *psStack_23c;
  undefined4 uStack_238;
  stack_st_OPENSSL_BLOCK sStack_234;
  stack_st_OPENSSL_BLOCK *psStack_220;
  stack_st_OPENSSL_BLOCK *psStack_21c;
  code *pcStack_218;
  stack_st_OPENSSL_BLOCK *psStack_214;
  stack_st_OPENSSL_BLOCK *psStack_210;
  stack_st_OPENSSL_BLOCK sStack_208;
  stack_st_OPENSSL_BLOCK *psStack_1f4;
  stack_st_OPENSSL_BLOCK *psStack_1f0;
  code *pcStack_1ec;
  stack_st_OPENSSL_BLOCK *psStack_1e8;
  stack_st_OPENSSL_BLOCK *psStack_1e4;
  uchar *puStack_1dc;
  stack_st_OPENSSL_BLOCK *psStack_1d8;
  stack_st_OPENSSL_BLOCK *psStack_1d4;
  stack_st_OPENSSL_BLOCK *psStack_1d0;
  stack_st_OPENSSL_BLOCK *psStack_1cc;
  undefined *puStack_1c8;
  stack_st_OPENSSL_BLOCK *psStack_1c4;
  stack_st_OPENSSL_BLOCK *psStack_1c0;
  stack_st_OPENSSL_BLOCK *psStack_1bc;
  stack_st_OPENSSL_BLOCK *psStack_1b8;
  code *pcStack_1b4;
  stack_st_OPENSSL_BLOCK *psStack_1a0;
  undefined *puStack_198;
  stack_st_OPENSSL_BLOCK *psStack_190;
  stack_st_OPENSSL_BLOCK **ppsStack_18c;
  stack_st_OPENSSL_BLOCK *psStack_188;
  stack_st_OPENSSL_BLOCK *psStack_184;
  undefined *puStack_180;
  stack_st_OPENSSL_BLOCK *psStack_17c;
  stack_st_OPENSSL_BLOCK *psStack_178;
  stack_st_OPENSSL_BLOCK *psStack_174;
  stack_st_OPENSSL_BLOCK *psStack_170;
  code *pcStack_16c;
  stack_st_OPENSSL_BLOCK *psStack_158;
  undefined *puStack_150;
  stack_st_OPENSSL_BLOCK *psStack_144;
  stack_st_OPENSSL_BLOCK *psStack_13c;
  undefined auStack_138 [4];
  char **ppcStack_134;
  stack_st_OPENSSL_BLOCK sStack_130;
  stack_st_OPENSSL_BLOCK *psStack_11c;
  stack_st_OPENSSL_BLOCK *psStack_118;
  code *pcStack_114;
  stack_st_OPENSSL_BLOCK *local_100;
  int local_fc;
  int *local_f8;
  undefined *local_f0;
  stack_st_OPENSSL_BLOCK *local_e4;
  stack_st_OPENSSL_BLOCK *local_e0;
  stack_st_OPENSSL_BLOCK *local_dc;
  stack_st_OPENSSL_BLOCK **local_d8;
  int *local_d4;
  stack_st_OPENSSL_BLOCK *local_d0;
  int *local_cc;
  int local_c8;
  char *local_c4;
  stack_st_OPENSSL_BLOCK *local_c0;
  undefined local_bc [8];
  undefined auStack_b4 [4];
  stack_st_OPENSSL_BLOCK *local_b0;
  undefined local_ac [8];
  undefined auStack_a4 [8];
  char **local_9c;
  int local_98;
  _func_257 *local_94;
  undefined local_90 [16];
  _func_257 *local_80;
  int local_7c;
  uint local_78;
  stack_st_OPENSSL_BLOCK *local_74;
  stack_st_OPENSSL_BLOCK *local_70;
  stack_st_OPENSSL_BLOCK *local_6c;
  code *local_68;
  stack_st_OPENSSL_BLOCK *local_64;
  stack_st_OPENSSL_BLOCK *local_60;
  stack_st_OPENSSL_BLOCK local_58;
  stack_st_OPENSSL_BLOCK *local_44;
  stack_st_OPENSSL_BLOCK *local_40;
  code *local_3c;
  stack_st_OPENSSL_BLOCK *local_38;
  stack_st_OPENSSL_BLOCK *local_34;
  stack_st_OPENSSL_BLOCK *local_2c;
  
  local_d4 = param_7;
  local_d8 = (stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  local_f0 = &_gp;
  local_2c = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  psVar2 = (stack_st_OPENSSL_BLOCK *)(uint)(param_6 < 0x15);
  psStack_1d8 = param_3;
  psStack_178 = param_4;
  local_dc = (stack_st_OPENSSL_BLOCK *)param_2;
  if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
    *param_7 = 0xc5;
    local_bc._4_4_ = unaff_s4;
  }
  else if (((param_1 == (stack_st_OPENSSL_BLOCK **)0x0) ||
           (unaff_s0 = *param_1, unaff_s0 == (stack_st_OPENSSL_BLOCK *)0x0)) &&
          (unaff_s0 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)(),
          unaff_s0 == (stack_st_OPENSSL_BLOCK *)0x0)) {
    psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
    unaff_s1 = param_3;
    unaff_s3 = param_4;
    local_bc._4_4_ = unaff_s4;
  }
  else {
    psStack_178 = (stack_st_OPENSSL_BLOCK *)auStack_b4;
    psStack_1d8 = (stack_st_OPENSSL_BLOCK *)(local_bc + 4);
    param_2 = local_bc;
    local_c0 = (stack_st_OPENSSL_BLOCK *)(local_dc->stack).num;
    local_100 = param_3;
    uVar3 = (**(code **)(local_f0 + -0x6e30))(&local_c0);
    if ((uVar3 & 0x80) == 0) {
      if (local_bc._4_4_ == param_4) {
        if ((uVar3 & 0x20) != 0) {
          local_7c = 0;
          local_60 = local_dc;
          local_90._12_4_ = local_c0;
          local_6c = local_bc._0_4_;
          local_70 = param_5;
          if (param_3 == (stack_st_OPENSSL_BLOCK *)0x0) {
            local_68 = (code *)0x0;
          }
          else {
            local_68 = (code *)((int)&(local_c0->stack).num + (int)&(param_3->stack).num);
          }
          local_bc._4_4_ = (stack_st_OPENSSL_BLOCK *)0x0;
          local_e4 = (stack_st_OPENSSL_BLOCK *)0x0;
          local_9c = (char **)0x0;
          unaff_s7 = (stack_st_OPENSSL_BLOCK *)(local_90 + 0xc);
          local_94 = (_func_257 *)0x0;
          unaff_s6 = (stack_st_OPENSSL_BLOCK *)auStack_a4;
          local_98 = 0;
          unaff_s8 = (stack_st_OPENSSL_BLOCK *)(local_ac + 4);
          local_c4 = "a_bytes.c";
          uVar6 = uVar3 & 1;
          local_78 = uVar3;
          local_74 = param_4;
          do {
            if (uVar6 == 0) {
              if (0 < (int)local_6c) goto LAB_0060e128;
LAB_0060e2f0:
              param_3 = (stack_st_OPENSSL_BLOCK *)(local_90 + 0xc);
              iVar8 = (**(code **)(local_f0 + -0x69e4))(param_3);
              if (iVar8 != 0) {
                (unaff_s0->stack).num = (int)local_bc._4_4_;
                if ((unaff_s0->stack).sorted != 0) {
                  (**(code **)(local_f0 + -0x7f58))();
                }
                (unaff_s0->stack).sorted = local_98;
                psVar2 = local_90._12_4_;
                if (local_e4 != (stack_st_OPENSSL_BLOCK *)0x0) {
                  (**(code **)(local_f0 + -0x6644))(local_e4);
                  psVar2 = local_90._12_4_;
                }
                goto LAB_0060e288;
              }
LAB_0060e1b0:
              if (local_e4 != (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060e1b8;
              goto LAB_0060e1cc;
            }
            param_2 = (char *)(local_68 + -(int)local_90._12_4_);
            local_80 = (_func_257 *)(**(code **)(local_f0 + -0x69e0))(unaff_s7);
            if (local_80 != (_func_257 *)0x0) goto LAB_0060e2f0;
LAB_0060e128:
            unaff_s5 = local_70;
            param_3 = (stack_st_OPENSSL_BLOCK *)(local_90 + 0xc);
            local_e0 = local_74;
            local_64 = local_90._12_4_;
            param_4 = (stack_st_OPENSSL_BLOCK *)(local_68 + -(int)local_90._12_4_);
            if (param_6 == 0x14) {
              local_7c = 0xc5;
              goto LAB_0060e1b0;
            }
            param_3 = local_e4;
            if ((local_e4 == (stack_st_OPENSSL_BLOCK *)0x0) &&
               (param_3 = (stack_st_OPENSSL_BLOCK *)(**(code **)(local_f0 + -0x6650))(),
               param_3 == (stack_st_OPENSSL_BLOCK *)0x0)) goto LAB_0060e1cc;
            param_2 = auStack_b4 + 8;
            local_b0 = local_90._12_4_;
            psStack_1d8 = unaff_s8;
            psStack_178 = unaff_s6;
            local_100 = param_4;
            uVar3 = (**(code **)(local_f0 + -0x6e30))(auStack_b4 + 4);
            if ((uVar3 & 0x80) != 0) {
              local_7c = 0x66;
LAB_0060e194:
              if (param_3 != local_e4) {
                (**(code **)(local_f0 + -0x6644))(param_3);
              }
              goto LAB_0060e1b0;
            }
            if (local_e0 != local_ac._4_4_) {
              local_7c = 0xa8;
              goto LAB_0060e194;
            }
            if ((uVar3 & 0x20) == 0) {
              if (local_ac._0_4_ == (stack_st_OPENSSL_BLOCK *)0x0) {
                if ((param_3->stack).sorted == 0) {
                  param_4 = (stack_st_OPENSSL_BLOCK *)0x0;
                  local_90._12_4_ = local_b0;
                }
                else {
                  param_4 = (stack_st_OPENSSL_BLOCK *)0x0;
                  (**(code **)(local_f0 + -0x7f58))();
                  local_90._12_4_ = local_b0;
                }
              }
              else {
                if (((param_3->stack).num < (int)local_ac._0_4_) ||
                   (param_4 = (stack_st_OPENSSL_BLOCK *)(param_3->stack).sorted,
                   param_4 == (stack_st_OPENSSL_BLOCK *)0x0)) {
                  psStack_1d8 = (stack_st_OPENSSL_BLOCK *)&DAT_000000e9;
                  param_2 = local_c4;
                  param_4 = (stack_st_OPENSSL_BLOCK *)
                            (**(code **)(local_f0 + -0x7dd8))
                                      ((code *)((int)&((local_ac._0_4_)->stack).num + 1));
                  if (param_4 == (stack_st_OPENSSL_BLOCK *)0x0) {
                    local_7c = 0x41;
                    goto LAB_0060e194;
                  }
                  if ((param_3->stack).sorted != 0) {
                    (**(code **)(local_f0 + -0x7f58))();
                  }
                }
                psStack_1d8 = local_ac._0_4_;
                (**(code **)(local_f0 + -0x52f4))(param_4,local_b0);
                *(code *)((int)&(param_4->stack).num + (int)&((local_ac._0_4_)->stack).num) =
                     (code)0x0;
                local_90._12_4_ =
                     (stack_st_OPENSSL_BLOCK *)
                     ((int)&(local_b0->stack).num + (int)&((local_ac._0_4_)->stack).num);
              }
              (param_3->stack).num = (int)local_ac._0_4_;
              (param_3->stack).sorted = (int)param_4;
              (param_3->stack).data = (char **)local_e0;
              psVar2 = local_ac._0_4_;
            }
            else {
              local_58.stack.sorted = 0;
              local_58.stack.num = (int)local_b0;
              local_40 = local_ac._0_4_;
              local_58.stack.comp = (_func_257 *)local_e0;
              local_44 = unaff_s5;
              if (param_4 == (stack_st_OPENSSL_BLOCK *)0x0) {
                local_3c = (code *)0x0;
              }
              else {
                local_3c = (code *)((int)&(local_b0->stack).num + (int)&(param_4->stack).num);
              }
              local_d0 = &local_58;
              local_e0 = (stack_st_OPENSSL_BLOCK *)0x0;
              auStack_a4._4_4_ = (stack_st_OPENSSL_BLOCK **)0x0;
              unaff_s5 = (stack_st_OPENSSL_BLOCK *)(auStack_a4 + 4);
              local_cc = &local_58.stack.sorted;
              local_90._0_4_ = 0;
              param_4 = (stack_st_OPENSSL_BLOCK *)local_90;
              local_90._8_4_ = 0;
              local_90._4_4_ = (char **)0x0;
              local_c8 = param_6 + 2;
              param_2 = (char *)local_ac._0_4_;
              local_58.stack.num_alloc = uVar3;
              local_34 = unaff_s7;
              if ((uVar3 & 1) != 0) goto LAB_0060e4a8;
              while (pcVar20 = *(code **)(local_f0 + -0x69e4), 0 < (int)local_40) {
                while( true ) {
                  local_f8 = local_cc;
                  local_100 = local_44;
                  psStack_1d8 = (stack_st_OPENSSL_BLOCK *)(local_3c + -local_58.stack.num);
                  local_38 = (stack_st_OPENSSL_BLOCK *)local_58.stack.num;
                  local_fc = local_c8;
                  param_2 = (char *)local_d0;
                  psStack_178 = (stack_st_OPENSSL_BLOCK *)local_58.stack.comp;
                  iVar8 = int_d2i_ASN1_bytes(unaff_s5);
                  if (iVar8 == 0) goto LAB_0060e610;
                  param_2 = (char *)((int)&(local_e0->stack).num +
                                    (int)&((*auStack_a4._4_4_)->stack).num);
                  iVar8 = (**(code **)(local_f0 + -0x72a0))(param_4);
                  if (iVar8 == 0) {
                    local_58.stack.sorted = 7;
                    goto LAB_0060e610;
                  }
                  psStack_1d8 = *auStack_a4._4_4_;
                  param_2 = (char *)auStack_a4._4_4_[2];
                  (**(code **)(local_f0 + -0x52f4))
                            ((code *)((int)&(local_e0->stack).num + (int)local_90._4_4_));
                  if ((local_58.stack.num_alloc & 1U) == 0) {
                    param_2 = (char *)(local_58.stack.num - (int)local_38);
                    local_40 = (stack_st_OPENSSL_BLOCK *)((int)local_40 - (int)param_2);
                  }
                  local_e0 = (stack_st_OPENSSL_BLOCK *)
                             ((int)&(local_e0->stack).num + (int)&((*auStack_a4._4_4_)->stack).num);
                  if ((local_58.stack.num_alloc & 1U) == 0) break;
LAB_0060e4a8:
                  param_2 = (char *)(local_3c + -local_58.stack.num);
                  local_58.stack.data = (char **)(**(code **)(local_f0 + -0x69e0))(local_d0);
                  if (local_58.stack.data != (char **)0x0) {
                    pcVar20 = *(code **)(local_f0 + -0x69e4);
                    goto LAB_0060e4d0;
                  }
                }
              }
LAB_0060e4d0:
              iVar8 = (*pcVar20)(local_d0);
              if (iVar8 == 0) {
LAB_0060e610:
                if (auStack_a4._4_4_ != (stack_st_OPENSSL_BLOCK **)0x0) {
                  (**(code **)(local_f0 + -0x6644))();
                }
                if (local_90._4_4_ != (char **)0x0) {
                  (**(code **)(local_f0 + -0x7f58))();
                }
                local_7c = local_58.stack.sorted;
                goto LAB_0060e194;
              }
              (param_3->stack).num = (int)local_e0;
              if ((param_3->stack).sorted != 0) {
                (**(code **)(local_f0 + -0x7f58))();
              }
              (param_3->stack).sorted = (int)local_90._4_4_;
              if (auStack_a4._4_4_ != (stack_st_OPENSSL_BLOCK **)0x0) {
                (**(code **)(local_f0 + -0x6644))();
              }
              local_90._12_4_ = (stack_st_OPENSSL_BLOCK *)local_58.stack.num;
              psVar2 = (stack_st_OPENSSL_BLOCK *)(param_3->stack).num;
            }
            param_2 = (char *)((int)&((local_bc._4_4_)->stack).num + (int)&(psVar2->stack).num);
            iVar8 = (**(code **)(local_f0 + -0x72a0))(&local_9c);
            if (iVar8 == 0) goto LAB_0060e67c;
            psStack_1d8 = (stack_st_OPENSSL_BLOCK *)(param_3->stack).num;
            param_2 = (char *)(param_3->stack).sorted;
            (**(code **)(local_f0 + -0x52f4))
                      ((code *)((int)&((local_bc._4_4_)->stack).num + local_98));
            uVar6 = local_78 & 1;
            if (uVar6 == 0) {
              param_2 = (char *)((int)local_90._12_4_ - (int)local_64);
              local_6c = (stack_st_OPENSSL_BLOCK *)((int)local_6c - (int)param_2);
            }
            local_bc._4_4_ =
                 (stack_st_OPENSSL_BLOCK *)
                 ((int)&((local_bc._4_4_)->stack).num + (param_3->stack).num);
            local_e4 = param_3;
          } while( true );
        }
        if (local_bc._0_4_ == (stack_st_OPENSSL_BLOCK *)0x0) {
          if ((unaff_s0->stack).sorted == 0) {
            param_3 = (stack_st_OPENSSL_BLOCK *)0x0;
            psVar2 = local_c0;
          }
          else {
            param_3 = (stack_st_OPENSSL_BLOCK *)0x0;
            (**(code **)(local_f0 + -0x7f58))();
            psVar2 = local_c0;
          }
        }
        else {
          if ((unaff_s0->stack).num < (int)local_bc._0_4_) {
            pcVar20 = *(code **)(local_f0 + -0x7dd8);
LAB_0060e690:
            psStack_1d8 = (stack_st_OPENSSL_BLOCK *)&DAT_000000e9;
            param_2 = "a_bytes.c";
            param_3 = (stack_st_OPENSSL_BLOCK *)
                      (*pcVar20)((code *)((int)&((local_bc._0_4_)->stack).num + 1));
            if (param_3 == (stack_st_OPENSSL_BLOCK *)0x0) {
              *local_d4 = 0x41;
              goto LAB_0060e014;
            }
            if ((unaff_s0->stack).sorted != 0) {
              (**(code **)(local_f0 + -0x7f58))();
            }
          }
          else {
            param_3 = (stack_st_OPENSSL_BLOCK *)(unaff_s0->stack).sorted;
            pcVar20 = *(code **)(local_f0 + -0x7dd8);
            if (param_3 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060e690;
          }
          param_2 = (char *)local_c0;
          psStack_1d8 = local_bc._0_4_;
          (**(code **)(local_f0 + -0x52f4))(param_3);
          *(code *)((int)&(param_3->stack).num + (int)&((local_bc._0_4_)->stack).num) = (code)0x0;
          psVar2 = (stack_st_OPENSSL_BLOCK *)
                   ((int)&(local_c0->stack).num + (int)&((local_bc._0_4_)->stack).num);
        }
        (unaff_s0->stack).num = (int)local_bc._0_4_;
        (unaff_s0->stack).sorted = (int)param_3;
        (unaff_s0->stack).data = (char **)local_bc._4_4_;
LAB_0060e288:
        if (param_1 != (stack_st_OPENSSL_BLOCK **)0x0) {
          *param_1 = unaff_s0;
        }
        (local_dc->stack).num = (int)psVar2;
        psVar2 = unaff_s0;
        unaff_s1 = param_3;
        unaff_s3 = param_4;
        goto LAB_0060e038;
      }
      *local_d4 = 0xa8;
    }
    else {
      *local_d4 = 0x66;
      local_bc._4_4_ = unaff_s4;
    }
LAB_0060e014:
    unaff_s1 = param_3;
    unaff_s3 = param_4;
    if ((param_1 == (stack_st_OPENSSL_BLOCK **)0x0) ||
       (psVar2 = (stack_st_OPENSSL_BLOCK *)0x0, unaff_s0 != *param_1)) {
      (**(code **)(local_f0 + -0x6644))(unaff_s0);
      psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
  }
LAB_0060e038:
  if (local_2c == *local_d8) {
    return psVar2;
  }
  pcStack_114 = d2i_ASN1_type_bytes;
  psStack_1d4 = local_2c;
  (**(code **)(local_f0 + -0x5330))();
  puStack_180 = PTR___stack_chk_guard_006a9ae8;
  psStack_13c = (stack_st_OPENSSL_BLOCK *)((_STACK *)param_2)->num;
  pcVar17 = auStack_138 + 8;
  puStack_150 = &_gp;
  psVar2 = (stack_st_OPENSSL_BLOCK *)auStack_138;
  sStack_130.stack.data = *(char ***)PTR___stack_chk_guard_006a9ae8;
  psStack_158 = psStack_1d8;
  sStack_130.stack.sorted = (int)unaff_s0;
  sStack_130.stack.num_alloc = (int)unaff_s1;
  sStack_130.stack.comp = (_func_257 *)param_1;
  psStack_11c = unaff_s3;
  psStack_118 = local_bc._4_4_;
  uVar3 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&psStack_13c,psVar2,auStack_138 + 4);
  if ((uVar3 & 0x80) == 0) {
    psVar13 = (stack_st_OPENSSL_BLOCK *)0x99;
    if (0x1f < (int)ppcStack_134) goto LAB_0060e7d0;
    uVar3 = (**(code **)(puStack_150 + -0x60f8))();
    if (((uint)psStack_178 & uVar3) == 0) {
      psVar13 = (stack_st_OPENSSL_BLOCK *)0xa9;
      goto LAB_0060e7d0;
    }
    if (ppcStack_134 != (char **)0x3) {
      if (((psStack_1d4 == (stack_st_OPENSSL_BLOCK *)0x0) ||
          (psStack_1d8 = (stack_st_OPENSSL_BLOCK *)(psStack_1d4->stack).num,
          psStack_1d8 == (stack_st_OPENSSL_BLOCK *)0x0)) &&
         (psStack_1d8 = (stack_st_OPENSSL_BLOCK *)(**(code **)(puStack_150 + -0x6650))(),
         psStack_1d8 == (stack_st_OPENSSL_BLOCK *)0x0)) {
        psVar4 = (stack_st_OPENSSL_BLOCK *)0x0;
        goto LAB_0060e7f8;
      }
      psStack_178 = (stack_st_OPENSSL_BLOCK *)0x0;
      if (auStack_138 == (undefined  [4])0x0) {
LAB_0060e874:
        if ((psStack_1d8->stack).sorted != 0) {
          (**(code **)(puStack_150 + -0x7f58))();
        }
        (psStack_1d8->stack).sorted = (int)psStack_178;
        (psStack_1d8->stack).num = (int)auStack_138;
        (psStack_1d8->stack).data = ppcStack_134;
        if (psStack_1d4 != (stack_st_OPENSSL_BLOCK *)0x0) {
          (psStack_1d4->stack).num = (int)psStack_1d8;
        }
        ((_STACK *)param_2)->num = (int)psStack_13c;
        psVar4 = psStack_1d8;
        goto LAB_0060e7f8;
      }
      psStack_144 = (stack_st_OPENSSL_BLOCK *)0x680000;
      psStack_178 = (stack_st_OPENSSL_BLOCK *)
                    (**(code **)(puStack_150 + -0x7dd8))
                              ((code *)((int)&((_STACK *)auStack_138)->num + 1),"a_bytes.c",0x6b);
      if (psStack_178 != (stack_st_OPENSSL_BLOCK *)0x0) {
        psVar2 = psStack_13c;
        psVar13 = (stack_st_OPENSSL_BLOCK *)auStack_138;
        pcVar17 = (char *)psStack_144;
        (**(code **)(puStack_150 + -0x52f4))(psStack_178);
        *(code *)((int)&(psStack_178->stack).num + (int)&((_STACK *)auStack_138)->num) = (code)0x0;
        psStack_13c = (stack_st_OPENSSL_BLOCK *)
                      ((int)&(psStack_13c->stack).num + (int)&((_STACK *)auStack_138)->num);
        goto LAB_0060e874;
      }
      pcVar17 = (char *)(psStack_144 + -0x4e8);
      psVar13 = (stack_st_OPENSSL_BLOCK *)&DAT_00000041;
      psVar2 = (stack_st_OPENSSL_BLOCK *)&DAT_00000095;
      psStack_158 = (stack_st_OPENSSL_BLOCK *)&DAT_00000080;
      (**(code **)(puStack_150 + -0x6eac))(0xd);
      if ((psStack_1d4 == (stack_st_OPENSSL_BLOCK *)0x0) ||
         (psStack_1d8 != (stack_st_OPENSSL_BLOCK *)(psStack_1d4->stack).num)) {
        (**(code **)(puStack_150 + -0x6644))(psStack_1d8);
        psVar4 = (stack_st_OPENSSL_BLOCK *)0x0;
        goto LAB_0060e7f8;
      }
      goto LAB_0060e7f4;
    }
    psVar2 = (stack_st_OPENSSL_BLOCK *)param_2;
    psVar13 = psStack_1d8;
    psVar4 = (stack_st_OPENSSL_BLOCK *)(**(code **)(puStack_150 + -0x55e8))(psStack_1d4);
  }
  else {
    psVar13 = (stack_st_OPENSSL_BLOCK *)0x0;
LAB_0060e7d0:
    psVar2 = (stack_st_OPENSSL_BLOCK *)&DAT_00000095;
    pcVar17 = "a_bytes.c";
    psStack_158 = (stack_st_OPENSSL_BLOCK *)&DAT_00000080;
    (**(code **)(puStack_150 + -0x6eac))(0xd);
LAB_0060e7f4:
    psVar4 = (stack_st_OPENSSL_BLOCK *)0x0;
  }
LAB_0060e7f8:
  if ((stack_st_OPENSSL_BLOCK *)sStack_130.stack.data == *(stack_st_OPENSSL_BLOCK **)puStack_180) {
    return psVar4;
  }
  pcStack_16c = i2d_ASN1_bytes;
  psVar4 = (stack_st_OPENSSL_BLOCK *)sStack_130.stack.data;
  (**(code **)(puStack_150 + -0x5330))();
  puStack_30c = PTR___stack_chk_guard_006a9ae8;
  puStack_198 = &_gp;
  ppsStack_18c = *(stack_st_OPENSSL_BLOCK ***)PTR___stack_chk_guard_006a9ae8;
  psVar5 = (stack_st_OPENSSL_BLOCK *)0x0;
  psVar10 = psVar2;
  psStack_398 = psVar13;
  psVar18 = (stack_st_OPENSSL_BLOCK *)pcVar17;
  psStack_1d0 = (stack_st_OPENSSL_BLOCK *)puStack_180;
  psStack_188 = psStack_1d8;
  psStack_184 = psStack_1d4;
  psStack_17c = (stack_st_OPENSSL_BLOCK *)param_2;
  psStack_174 = unaff_s5;
  psStack_170 = unaff_s6;
  if (psVar4 != (stack_st_OPENSSL_BLOCK *)0x0) {
    psStack_1d0 = psVar13;
    if (psVar13 == (stack_st_OPENSSL_BLOCK *)0x3) {
      psVar5 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_i2d_ASN1_BIT_STRING_006a97fc)();
      psVar10 = psVar2;
      psVar18 = (stack_st_OPENSSL_BLOCK *)pcVar17;
    }
    else {
      psVar19 = (stack_st_OPENSSL_BLOCK *)(psVar4->stack).num;
      psVar10 = psVar19;
      psVar5 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_object_size_006a83e4)(0);
      psStack_1d8 = psVar4;
      psStack_1d4 = psVar5;
      param_2 = (char *)psVar2;
      unaff_s5 = psVar19;
      unaff_s6 = (stack_st_OPENSSL_BLOCK *)pcVar17;
      if (psVar2 != (stack_st_OPENSSL_BLOCK *)0x0) {
        psStack_190 = (stack_st_OPENSSL_BLOCK *)(psVar2->stack).num;
        psVar18 = psVar13;
        psStack_1a0 = (stack_st_OPENSSL_BLOCK *)pcVar17;
        (**(code **)(puStack_198 + -0x69f8))
                  (&psStack_190,&psVar13[-1].stack.data < &SUB_00000002,psVar19);
        psStack_398 = (stack_st_OPENSSL_BLOCK *)(psVar4->stack).num;
        psVar10 = (stack_st_OPENSSL_BLOCK *)(psVar4->stack).sorted;
        (**(code **)(puStack_198 + -0x52f4))(psStack_190);
        (psVar2->stack).num = (int)&(psStack_190->stack).num + (psVar4->stack).num;
      }
    }
  }
  if (ppsStack_18c == *(stack_st_OPENSSL_BLOCK ***)puStack_30c) {
    return psVar5;
  }
  pcStack_1b4 = d2i_ASN1_bytes;
  ppsStack_314 = ppsStack_18c;
  (**(code **)(puStack_198 + -0x5330))();
  ppuStack_280 = (uchar **)PTR___stack_chk_guard_006a9ae8;
  puStack_1c8 = puStack_30c;
  puStack_298 = &_gp;
  puStack_1dc = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  pcVar17 = (char *)psVar18;
  psStack_310 = psVar18;
  psStack_284 = psVar10;
  psStack_1cc = (stack_st_OPENSSL_BLOCK *)param_2;
  psStack_1c4 = unaff_s5;
  psStack_1c0 = unaff_s6;
  psStack_1bc = unaff_s7;
  psStack_1b8 = unaff_s8;
  if (ppsStack_314 == (stack_st_OPENSSL_BLOCK **)0x0) {
LAB_0060ebd4:
    pcStack_388 = (char *)psStack_398;
    psStack_2c0 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    pcStack_38c = (char *)psVar10;
    if (psStack_2c0 != (stack_st_OPENSSL_BLOCK *)0x0) {
      pcVar17 = auStack_264;
      pcStack_388 = auStack_26c + 4;
      pcStack_38c = auStack_26c;
      psStack_270 = (stack_st_OPENSSL_BLOCK *)(psStack_284->stack).num;
      psStack_2a8 = psStack_398;
      uVar3 = (**(code **)(puStack_298 + -0x6e30))(&psStack_270);
      psVar2 = psStack_2c0;
      if ((uVar3 & 0x80) == 0) goto LAB_0060ec1c;
      psStack_398 = (stack_st_OPENSSL_BLOCK *)0x66;
      goto LAB_0060ec2c;
    }
    goto LAB_0060eb90;
  }
  psStack_2c0 = *ppsStack_314;
  pcVar17 = auStack_264;
  if (psStack_2c0 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060ebd4;
  psStack_270 = (stack_st_OPENSSL_BLOCK *)(psVar10->stack).num;
  pcStack_388 = auStack_26c + 4;
  pcStack_38c = auStack_26c;
  psStack_2a8 = psStack_398;
  uVar3 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&psStack_270);
  psVar2 = psStack_2c0;
  if ((uVar3 & 0x80) != 0) {
    psStack_398 = (stack_st_OPENSSL_BLOCK *)0x66;
    if (psStack_2c0 != *ppsStack_314) {
      pcVar20 = *(code **)(puStack_298 + -0x6644);
      goto LAB_0060eb80;
    }
    goto LAB_0060ec50;
  }
LAB_0060ec1c:
  psStack_2c0 = psVar2;
  if (psVar18 != auStack_26c._4_4_) {
    psStack_398 = (stack_st_OPENSSL_BLOCK *)&DAT_000000a8;
    goto LAB_0060ec2c;
  }
  if ((uVar3 & 0x20) != 0) {
    sStack_234.stack.sorted = 0;
    psStack_210 = psStack_284;
    sStack_234.stack.num = (int)psStack_270;
    psStack_21c = auStack_26c._0_4_;
    psStack_220 = psStack_1a0;
    if (psStack_398 == (stack_st_OPENSSL_BLOCK *)0x0) {
      pcStack_218 = (code *)0x0;
    }
    else {
      pcStack_218 = (code *)((int)&(psStack_270->stack).num + (int)&(psStack_398->stack).num);
    }
    puStack_30c = (undefined *)0x0;
    ppsStack_288 = (stack_st_OPENSSL_BLOCK **)0x0;
    ppcStack_24c = (char **)0x0;
    unaff_s7 = &sStack_234;
    p_Stack_244 = (_func_257 *)0x0;
    unaff_s6 = (stack_st_OPENSSL_BLOCK *)auStack_254;
    iStack_248 = 0;
    psStack_310 = (stack_st_OPENSSL_BLOCK *)(auStack_25c + 4);
    pcStack_274 = "a_bytes.c";
    uVar6 = uVar3 & 1;
    sStack_234.stack.num_alloc = uVar3;
    sStack_234.stack.comp = (_func_257 *)psVar18;
    do {
      if (uVar6 == 0) {
        if (0 < (int)psStack_21c) goto LAB_0060ed04;
LAB_0060eea4:
        psStack_398 = &sStack_234;
        iVar8 = (**(code **)(puStack_298 + -0x69e4))(psStack_398);
        if (iVar8 != 0) {
          (psVar2->stack).num = (int)puStack_30c;
          if ((psVar2->stack).sorted != 0) {
            (**(code **)(puStack_298 + -0x7f58))();
          }
          (psVar2->stack).sorted = iStack_248;
          psVar13 = (stack_st_OPENSSL_BLOCK *)sStack_234.stack.num;
          if (ppsStack_288 != (stack_st_OPENSSL_BLOCK **)0x0) {
            (**(code **)(puStack_298 + -0x6644))(ppsStack_288);
            psVar13 = (stack_st_OPENSSL_BLOCK *)sStack_234.stack.num;
          }
          goto LAB_0060ee40;
        }
LAB_0060ed80:
        if (ppsStack_288 != (stack_st_OPENSSL_BLOCK **)0x0) goto LAB_0060ed88;
        goto LAB_0060ed9c;
      }
      pcStack_38c = (char *)(pcStack_218 + -sStack_234.stack.num);
      sStack_234.stack.data = (char **)(**(code **)(puStack_298 + -0x69e0))(unaff_s7);
      if (sStack_234.stack.data != (char **)0x0) goto LAB_0060eea4;
LAB_0060ed04:
      psVar13 = (stack_st_OPENSSL_BLOCK *)sStack_234.stack.comp;
      psStack_28c = psStack_220;
      psStack_214 = (stack_st_OPENSSL_BLOCK *)sStack_234.stack.num;
      unaff_s5 = (stack_st_OPENSSL_BLOCK *)(pcStack_218 + -sStack_234.stack.num);
      ppsVar15 = ppsStack_288;
      if ((ppsStack_288 == (stack_st_OPENSSL_BLOCK **)0x0) &&
         (ppsVar15 = (stack_st_OPENSSL_BLOCK **)(**(code **)(puStack_298 + -0x6650))(),
         ppsVar15 == (stack_st_OPENSSL_BLOCK **)0x0)) goto LAB_0060ed9c;
      pcStack_38c = auStack_264 + 8;
      psStack_260 = (stack_st_OPENSSL_BLOCK *)sStack_234.stack.num;
      pcStack_388 = (char *)psStack_310;
      pcVar17 = (char *)unaff_s6;
      psStack_2a8 = unaff_s5;
      uVar3 = (**(code **)(puStack_298 + -0x6e30))(auStack_264 + 4);
      if ((uVar3 & 0x80) != 0) {
        sStack_234.stack.sorted = 0x66;
LAB_0060ed64:
        if (ppsVar15 != ppsStack_288) {
          (**(code **)(puStack_298 + -0x6644))(ppsVar15);
        }
        goto LAB_0060ed80;
      }
      if (psVar13 != auStack_25c._4_4_) {
        sStack_234.stack.sorted = (int)&DAT_000000a8;
        goto LAB_0060ed64;
      }
      if ((uVar3 & 0x20) == 0) {
        if (auStack_25c._0_4_ == (stack_st_OPENSSL_BLOCK *)0x0) {
          if (ppsVar15[2] == (stack_st_OPENSSL_BLOCK *)0x0) {
            unaff_s5 = (stack_st_OPENSSL_BLOCK *)0x0;
            sStack_234.stack.num = (int)psStack_260;
          }
          else {
            unaff_s5 = (stack_st_OPENSSL_BLOCK *)0x0;
            (**(code **)(puStack_298 + -0x7f58))();
            sStack_234.stack.num = (int)psStack_260;
          }
        }
        else {
          if (((int)*ppsVar15 < (int)auStack_25c._0_4_) ||
             (unaff_s5 = ppsVar15[2], unaff_s5 == (stack_st_OPENSSL_BLOCK *)0x0)) {
            pcStack_388 = &DAT_000000e9;
            pcStack_38c = pcStack_274;
            unaff_s5 = (stack_st_OPENSSL_BLOCK *)
                       (**(code **)(puStack_298 + -0x7dd8))
                                 ((code *)((int)&((auStack_25c._0_4_)->stack).num + 1));
            if (unaff_s5 == (stack_st_OPENSSL_BLOCK *)0x0) {
              sStack_234.stack.sorted = (int)&DAT_00000041;
              goto LAB_0060ed64;
            }
            if (ppsVar15[2] != (stack_st_OPENSSL_BLOCK *)0x0) {
              (**(code **)(puStack_298 + -0x7f58))();
            }
          }
          pcStack_388 = (char *)auStack_25c._0_4_;
          (**(code **)(puStack_298 + -0x52f4))(unaff_s5,psStack_260);
          *(code *)((int)&(unaff_s5->stack).num + (int)&((auStack_25c._0_4_)->stack).num) =
               (code)0x0;
          sStack_234.stack.num =
               (int)((int)&(psStack_260->stack).num + (int)&((auStack_25c._0_4_)->stack).num);
        }
        *ppsVar15 = auStack_25c._0_4_;
        ppsVar15[2] = unaff_s5;
        ppsVar15[1] = psVar13;
        psVar13 = auStack_25c._0_4_;
      }
      else {
        sStack_208.stack.sorted = 0;
        sStack_208.stack.num = (int)psStack_260;
        psStack_1f0 = auStack_25c._0_4_;
        sStack_208.stack.comp = (_func_257 *)psVar13;
        psStack_1f4 = psStack_28c;
        if (unaff_s5 == (stack_st_OPENSSL_BLOCK *)0x0) {
          pcStack_1ec = (code *)0x0;
        }
        else {
          pcStack_1ec = (code *)((int)&(psStack_260->stack).num + (int)&(unaff_s5->stack).num);
        }
        psStack_27c = &sStack_208;
        psStack_28c = (stack_st_OPENSSL_BLOCK *)0x0;
        auStack_254._4_4_ = (stack_st_OPENSSL_BLOCK **)0x0;
        unaff_s5 = (stack_st_OPENSSL_BLOCK *)(auStack_254 + 4);
        piStack_278 = &sStack_208.stack.sorted;
        p_Stack_240 = (_func_257 *)0x0;
        uStack_238 = 0;
        psStack_23c = (stack_st_OPENSSL_BLOCK *)0x0;
        pcStack_38c = (char *)auStack_25c._0_4_;
        sStack_208.stack.num_alloc = uVar3;
        psStack_1e4 = unaff_s7;
        if ((uVar3 & 1) != 0) goto LAB_0060f054;
        while (pcVar20 = *(code **)(puStack_298 + -0x69e4), 0 < (int)psStack_1f0) {
          while( true ) {
            piStack_2a0 = piStack_278;
            psStack_2a8 = psStack_1f4;
            pcStack_388 = (char *)(pcStack_1ec + -sStack_208.stack.num);
            psStack_1e8 = (stack_st_OPENSSL_BLOCK *)sStack_208.stack.num;
            uStack_2a4 = 2;
            pcStack_38c = (char *)psStack_27c;
            pcVar17 = (char *)sStack_208.stack.comp;
            iVar8 = int_d2i_ASN1_bytes(unaff_s5);
            if (iVar8 == 0) goto LAB_0060f1ac;
            pcStack_38c = (char *)((int)&(psStack_28c->stack).num +
                                  (int)&((*auStack_254._4_4_)->stack).num);
            iVar8 = (**(code **)(puStack_298 + -0x72a0))(&p_Stack_240);
            if (iVar8 == 0) {
              sStack_208.stack.sorted = (int)&DAT_00000007;
              goto LAB_0060f1ac;
            }
            pcStack_388 = (char *)*auStack_254._4_4_;
            pcStack_38c = (char *)auStack_254._4_4_[2];
            (**(code **)(puStack_298 + -0x52f4))
                      ((code *)((int)&(psStack_23c->stack).num + (int)&(psStack_28c->stack).num));
            if ((sStack_208.stack.num_alloc & 1U) == 0) {
              pcStack_38c = (char *)(sStack_208.stack.num - (int)psStack_1e8);
              psStack_1f0 = (stack_st_OPENSSL_BLOCK *)((int)psStack_1f0 - (int)pcStack_38c);
            }
            psStack_28c = (stack_st_OPENSSL_BLOCK *)
                          ((int)&(psStack_28c->stack).num + (int)&((*auStack_254._4_4_)->stack).num)
            ;
            if ((sStack_208.stack.num_alloc & 1U) == 0) break;
LAB_0060f054:
            pcStack_38c = (char *)(pcStack_1ec + -sStack_208.stack.num);
            sStack_208.stack.data = (char **)(**(code **)(puStack_298 + -0x69e0))(psStack_27c);
            if (sStack_208.stack.data != (char **)0x0) {
              pcVar20 = *(code **)(puStack_298 + -0x69e4);
              goto LAB_0060f07c;
            }
          }
        }
LAB_0060f07c:
        iVar8 = (*pcVar20)(psStack_27c);
        if (iVar8 == 0) {
LAB_0060f1ac:
          if (auStack_254._4_4_ != (stack_st_OPENSSL_BLOCK **)0x0) {
            (**(code **)(puStack_298 + -0x6644))();
          }
          if (psStack_23c != (stack_st_OPENSSL_BLOCK *)0x0) {
            (**(code **)(puStack_298 + -0x7f58))();
          }
          sStack_234.stack.sorted = sStack_208.stack.sorted;
          goto LAB_0060ed64;
        }
        *ppsVar15 = psStack_28c;
        if (ppsVar15[2] != (stack_st_OPENSSL_BLOCK *)0x0) {
          (**(code **)(puStack_298 + -0x7f58))();
        }
        ppsVar15[2] = psStack_23c;
        if (auStack_254._4_4_ != (stack_st_OPENSSL_BLOCK **)0x0) {
          (**(code **)(puStack_298 + -0x6644))();
        }
        sStack_234.stack.num = sStack_208.stack.num;
        psVar13 = *ppsVar15;
      }
      pcStack_38c = puStack_30c + (int)&(psVar13->stack).num;
      iVar8 = (**(code **)(puStack_298 + -0x72a0))(&ppcStack_24c);
      if (iVar8 == 0) goto LAB_0060f214;
      pcStack_388 = (char *)*ppsVar15;
      pcStack_38c = (char *)ppsVar15[2];
      (**(code **)(puStack_298 + -0x52f4))(puStack_30c + iStack_248);
      uVar6 = sStack_234.stack.num_alloc & 1;
      if (uVar6 == 0) {
        pcStack_38c = (char *)(sStack_234.stack.num - (int)psStack_214);
        psStack_21c = (stack_st_OPENSSL_BLOCK *)((int)psStack_21c - (int)pcStack_38c);
      }
      puStack_30c = puStack_30c + (int)&((*ppsVar15)->stack).num;
      ppsStack_288 = ppsVar15;
    } while( true );
  }
  if (auStack_26c._0_4_ == (stack_st_OPENSSL_BLOCK *)0x0) {
    if ((psVar2->stack).sorted == 0) {
      psStack_398 = (stack_st_OPENSSL_BLOCK *)0x0;
      psVar13 = psStack_270;
    }
    else {
      psStack_398 = (stack_st_OPENSSL_BLOCK *)0x0;
      (**(code **)(puStack_298 + -0x7f58))();
      psVar13 = psStack_270;
    }
  }
  else {
    if ((psVar2->stack).num < (int)auStack_26c._0_4_) {
      pcVar20 = *(code **)(puStack_298 + -0x7dd8);
LAB_0060f228:
      pcStack_388 = &DAT_000000e9;
      pcStack_38c = "a_bytes.c";
      psStack_398 = (stack_st_OPENSSL_BLOCK *)
                    (*pcVar20)((code *)((int)&((auStack_26c._0_4_)->stack).num + 1));
      if (psStack_398 == (stack_st_OPENSSL_BLOCK *)0x0) {
        psStack_398 = (stack_st_OPENSSL_BLOCK *)&DAT_00000041;
        goto LAB_0060ec2c;
      }
      if ((psVar2->stack).sorted != 0) {
        (**(code **)(puStack_298 + -0x7f58))();
      }
    }
    else {
      psStack_398 = (stack_st_OPENSSL_BLOCK *)(psVar2->stack).sorted;
      pcVar20 = *(code **)(puStack_298 + -0x7dd8);
      if (psStack_398 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060f228;
    }
    pcStack_38c = (char *)psStack_270;
    pcStack_388 = (char *)auStack_26c._0_4_;
    (**(code **)(puStack_298 + -0x52f4))(psStack_398);
    *(code *)((int)&(psStack_398->stack).num + (int)&((auStack_26c._0_4_)->stack).num) = (code)0x0;
    psVar13 = (stack_st_OPENSSL_BLOCK *)
              ((int)&(psStack_270->stack).num + (int)&((auStack_26c._0_4_)->stack).num);
  }
  (psVar2->stack).num = (int)auStack_26c._0_4_;
  (psVar2->stack).sorted = (int)psStack_398;
  (psVar2->stack).data = (char **)psVar18;
LAB_0060ee40:
  if (ppsStack_314 != (stack_st_OPENSSL_BLOCK **)0x0) {
    *ppsStack_314 = psVar2;
  }
  (psStack_284->stack).num = (int)psVar13;
  goto LAB_0060eb94;
LAB_0060e67c:
  local_7c = 7;
  local_e4 = param_3;
LAB_0060e1b8:
  (**(code **)(local_f0 + -0x6644))(local_e4);
LAB_0060e1cc:
  if (local_98 != 0) {
    (**(code **)(local_f0 + -0x7f58))();
  }
  *local_d4 = local_7c;
  goto LAB_0060e014;
LAB_0060f214:
  sStack_234.stack.sorted = (int)&DAT_00000007;
  ppsStack_288 = ppsVar15;
LAB_0060ed88:
  (**(code **)(puStack_298 + -0x6644))(ppsStack_288);
LAB_0060ed9c:
  psStack_398 = (stack_st_OPENSSL_BLOCK *)sStack_234.stack.sorted;
  if (iStack_248 != 0) {
    (**(code **)(puStack_298 + -0x7f58))();
    psStack_398 = (stack_st_OPENSSL_BLOCK *)sStack_234.stack.sorted;
  }
LAB_0060ec2c:
  pcVar20 = *(code **)(puStack_298 + -0x6644);
  if ((ppsStack_314 == (stack_st_OPENSSL_BLOCK **)0x0) || (*ppsStack_314 != psStack_2c0)) {
LAB_0060eb80:
    (*pcVar20)(psStack_2c0);
    if (psStack_398 != (stack_st_OPENSSL_BLOCK *)0x0) {
LAB_0060ec50:
      pcVar20 = *(code **)(puStack_298 + -0x6eac);
      goto LAB_0060ec58;
    }
  }
  else if (psStack_398 != (stack_st_OPENSSL_BLOCK *)0x0) {
    pcVar20 = *(code **)(puStack_298 + -0x6eac);
LAB_0060ec58:
    pcStack_38c = (char *)0x8f;
    pcVar17 = "a_bytes.c";
    psStack_2a8 = (stack_st_OPENSSL_BLOCK *)0xaf;
    pcStack_388 = (char *)psStack_398;
    (*pcVar20)(0xd);
    psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
    goto LAB_0060eb94;
  }
LAB_0060eb90:
  psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
LAB_0060eb94:
  if (puStack_1dc == *ppuStack_280) {
    return psVar2;
  }
  uStack_2bc = 0x60f2d8;
  puStack_2c8 = puStack_1dc;
  (**(code **)(puStack_298 + -0x5330))();
  psStack_350 = (stack_st_OPENSSL_BLOCK *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_390 = &puStack_2c8;
  psStack_2c4 = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  psVar2 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_390,(long)pcStack_38c,pcStack_388,
                        (free_func *)pcVar17,0x10,0);
  if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
    pcStack_38c = &DAT_0000006e;
    pcStack_388 = "asn_pack.c";
    ppuStack_390 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (psStack_2c4 == *(stack_st_OPENSSL_BLOCK **)psStack_350) {
    return psVar2;
  }
  pcStack_2fc = ASN1_seq_pack;
  psVar2 = psStack_2c4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_394 = PTR___stack_chk_guard_006a9ae8;
  puStack_31c = (undefined *)psStack_350;
  ppiStack_324 = *(int ***)PTR___stack_chk_guard_006a9ae8;
  psStack_318 = psStack_398;
  psStack_308 = unaff_s5;
  psStack_304 = unaff_s6;
  psStack_300 = unaff_s7;
  psVar13 = (stack_st_OPENSSL_BLOCK *)
            i2d_ASN1_SET(psVar2,(uchar **)0x0,(undefined1 *)ppuStack_390,0x10,0,0);
  if (psVar13 == (stack_st_OPENSSL_BLOCK *)0x0) {
    ppsVar15 = (stack_st_OPENSSL_BLOCK **)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
  }
  else {
    psStack_350 = (stack_st_OPENSSL_BLOCK *)
                  (*(code *)PTR_CRYPTO_malloc_006a7008)(psVar13,"asn_pack.c",0x62);
    psStack_398 = psVar13;
    if (psStack_350 == (stack_st_OPENSSL_BLOCK *)0x0) {
      ppsVar15 = (stack_st_OPENSSL_BLOCK **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
      psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
    else {
      ppsVar15 = &psStack_328;
      psStack_328 = psStack_350;
      i2d_ASN1_SET(psVar2,(uchar **)ppsVar15,(undefined1 *)ppuStack_390,0x10,0,0);
      if ((stack_st_OPENSSL_BLOCK *)pcStack_388 != (stack_st_OPENSSL_BLOCK *)0x0) {
        ((_STACK *)pcStack_388)->num = (int)psVar13;
      }
      psVar2 = psStack_350;
      if ((stack_st_OPENSSL_BLOCK *)pcStack_38c != (stack_st_OPENSSL_BLOCK *)0x0) {
        ((_STACK *)pcStack_38c)->num = (int)psStack_350;
      }
    }
  }
  if (ppiStack_324 == *(int ***)puStack_394) {
    return psVar2;
  }
  pcStack_34c = ASN1_unpack_string;
  ppiVar11 = ppiStack_324;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_39c = PTR___stack_chk_guard_006a9ae8;
  piStack_358 = ppiVar11[2];
  ppsVar14 = (stack_st_OPENSSL_BLOCK **)*ppiVar11;
  ppiVar11 = &piStack_358;
  puStack_368 = &_gp;
  iStack_354 = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)ppsVar15)(0);
  if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
    ppsVar14 = (stack_st_OPENSSL_BLOCK **)&DAT_0000006e;
    uStack_370 = 0x79;
    ppiVar11 = (int **)&DAT_00000088;
    psStack_35c = psVar2;
    (**(code **)(puStack_368 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    psVar2 = psStack_35c;
  }
  if (iStack_354 == *(int *)puStack_39c) {
    return psVar2;
  }
  pcStack_384 = ASN1_pack_string;
  iVar8 = iStack_354;
  (**(code **)(puStack_368 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_3a4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (ppsVar14 == (stack_st_OPENSSL_BLOCK **)0x0) {
    psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (psVar2 != (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppsVar15 = (stack_st_OPENSSL_BLOCK **)&DAT_00000041;
    piVar12 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    psVar13 = (stack_st_OPENSSL_BLOCK *)0x0;
  }
  else {
    psVar2 = *ppsVar14;
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
      psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060f754;
      *ppsVar14 = psVar2;
    }
LAB_0060f614:
    iVar7 = (*(code *)ppiVar11)(iVar8,0);
    (psVar2->stack).num = iVar7;
    if (iVar7 == 0) {
      ppsVar15 = (stack_st_OPENSSL_BLOCK **)&DAT_00000070;
      piVar12 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppsVar15 = (stack_st_OPENSSL_BLOCK **)&DAT_00000092;
      iStack_3a8 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar7,"asn_pack.c");
      if (iStack_3a8 != 0) {
        piVar12 = &iStack_3a8;
        (psVar2->stack).sorted = iStack_3a8;
        (*(code *)ppiVar11)(iVar8,piVar12);
        psVar13 = psVar2;
        goto LAB_0060f670;
      }
      ppsVar15 = (stack_st_OPENSSL_BLOCK **)&DAT_00000041;
      piVar12 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppsVar14 == (stack_st_OPENSSL_BLOCK **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(psVar2);
      psVar13 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
    else {
      psVar13 = *ppsVar14;
      if (psVar13 == (stack_st_OPENSSL_BLOCK *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(psVar2);
        *ppsVar14 = (stack_st_OPENSSL_BLOCK *)0x0;
      }
      else {
        psVar13 = (stack_st_OPENSSL_BLOCK *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_3a4 == *(int *)puVar1) {
    return psVar13;
  }
  iVar8 = iStack_3a4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppsVar15 == (stack_st_OPENSSL_BLOCK **)0x0) {
    psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
LAB_0060f874:
      uVar16 = 0x41;
      uVar9 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    psVar2 = *ppsVar15;
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
      psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060f874;
      *ppsVar15 = psVar2;
    }
  }
  if ((psVar2->stack).sorted != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    (psVar2->stack).sorted = 0;
  }
  iVar8 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar8,&(psVar2->stack).sorted,piVar12);
  (psVar2->stack).num = iVar8;
  if (iVar8 == 0) {
    uVar16 = 0x70;
    uVar9 = 0xba;
  }
  else {
    if ((psVar2->stack).sorted != 0) {
      return psVar2;
    }
    uVar16 = 0x41;
    uVar9 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar16,"asn_pack.c",uVar9);
  return (stack_st_OPENSSL_BLOCK *)0x0;
}

