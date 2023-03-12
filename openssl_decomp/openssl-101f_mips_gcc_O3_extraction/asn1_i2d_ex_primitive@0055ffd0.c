
/* WARNING: Type propagation algorithm not settling */

ASN1_ITEM *
asn1_i2d_ex_primitive
          (int *param_1,ASN1_ITEM *param_2,ASN1_ITEM *param_3,ASN1_ITEM *param_4,int param_5)

{
  undefined *puVar1;
  ASN1_ITEM *pAVar2;
  int *piVar3;
  ASN1_ITEM *pAVar4;
  uint uVar5;
  ASN1_ITEM *pAVar6;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM **ppAVar7;
  int iVar8;
  ASN1_VALUE **ppAVar9;
  ASN1_INTEGER *pAVar10;
  uchar *puVar11;
  ASN1_TEMPLATE *pAVar12;
  uchar **ppuVar13;
  ASN1_VALUE *pAVar14;
  ASN1_ITEM *pAVar15;
  void *pvVar16;
  ASN1_ITEM *pAVar17;
  uint uVar18;
  ASN1_ITEM *unaff_s0;
  ASN1_ITEM *unaff_s1;
  int iVar19;
  ASN1_ITEM *unaff_s7;
  ASN1_TEMPLATE *pAVar20;
  int iVar21;
  code *pcVar22;
  undefined *tag;
  ASN1_TEMPLATE *pAStack_e8;
  undefined *puStack_e4;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  ASN1_ITEM *pAStack_d4;
  int iStack_d0;
  int iStack_cc;
  ASN1_ITEM *pAStack_c4;
  ASN1_TEMPLATE AStack_c0;
  ASN1_ITEM *pAStack_ac;
  ASN1_ITEM *pAStack_a8;
  ASN1_ITEM *pAStack_a4;
  int *piStack_a0;
  ASN1_ITEM *pAStack_9c;
  ASN1_ITEM *pAStack_74;
  undefined auStack_6d [9];
  ASN1_ITEM *pAStack_64;
  ASN1_ITEM *pAStack_60;
  code *pcStack_5c;
  char local_35;
  ASN1_ITEM *local_34;
  ASN1_ITEM *local_30;
  ASN1_TEMPLATE *local_2c;
  
  tt = (ASN1_TEMPLATE *)PTR___stack_chk_guard_006aabf0;
  pAVar17 = (ASN1_ITEM *)param_3->utype;
  local_2c = *(ASN1_TEMPLATE **)PTR___stack_chk_guard_006aabf0;
  pAVar15 = param_2;
  local_34 = pAVar17;
  if (param_3->funcs == (void *)0x0) {
LAB_00560134:
    piVar3 = param_1;
    pAVar6 = param_4;
    if (param_3->itype == '\0') {
      if (pAVar17 == (ASN1_ITEM *)0x1) {
LAB_005602d8:
        if (*piVar3 == -1) {
          unaff_s0 = (ASN1_ITEM *)0xffffffff;
          pAVar2 = (ASN1_ITEM *)0x1;
        }
        else if (pAVar17 == (ASN1_ITEM *)0xfffffffc) {
          unaff_s0 = (ASN1_ITEM *)0x1;
          pAVar2 = (ASN1_ITEM *)0x1;
        }
        else if (*piVar3 == 0) {
          unaff_s0 = (ASN1_ITEM *)0x1;
          pAVar2 = (ASN1_ITEM *)0x1;
          if (param_3->size == 0) {
            unaff_s0 = (ASN1_ITEM *)0xffffffff;
          }
        }
        else {
          unaff_s0 = (ASN1_ITEM *)0x1;
          pAVar2 = (ASN1_ITEM *)0x1;
          if (0 < param_3->size) {
            unaff_s0 = (ASN1_ITEM *)0xffffffff;
          }
        }
        goto LAB_00560068;
      }
      pAVar10 = (ASN1_INTEGER *)*param_1;
      if (pAVar10 != (ASN1_INTEGER *)0x0) {
LAB_00560154:
        if (pAVar17 == (ASN1_ITEM *)0xfffffffc) {
          piVar3 = &pAVar10->type;
          local_34 = (ASN1_ITEM *)pAVar10->length;
        }
        goto LAB_0056016c;
      }
      pAVar2 = (ASN1_ITEM *)0x0;
      if ((long *)0x1 < &pAVar17[-1].tcount) goto LAB_005604a0;
    }
    else {
      pAVar10 = (ASN1_INTEGER *)*param_1;
      if (pAVar10 == (ASN1_INTEGER *)0x0) {
        pAVar2 = (ASN1_ITEM *)0x0;
        if (&pAVar17[-1].tcount < &SUB_00000002) goto LAB_005600ec;
LAB_005604a0:
        unaff_s0 = (ASN1_ITEM *)0xffffffff;
        pAVar2 = pAVar17;
LAB_00560068:
        unaff_s1 = (ASN1_ITEM *)(uint)(pAVar2 != (ASN1_ITEM *)0xfffffffd);
        if (unaff_s0 == (ASN1_ITEM *)0xffffffff) goto LAB_0056012c;
        goto LAB_00560078;
      }
      if (param_3->itype != '\x05') goto LAB_00560154;
      local_34 = (ASN1_ITEM *)pAVar10->type;
LAB_0056016c:
      pAVar2 = local_34;
      if (local_34 == (ASN1_ITEM *)&DAT_00000005) {
        unaff_s0 = (ASN1_ITEM *)0x0;
        goto LAB_00560068;
      }
      pcVar22 = (code *)PTR_i2c_ASN1_INTEGER_006a9eb0;
      if ((int)local_34 < 6) {
        if ((local_34 != (ASN1_ITEM *)&SUB_00000002) &&
           (pcVar22 = (code *)PTR_i2c_ASN1_BIT_STRING_006a9eac, local_34 != (ASN1_ITEM *)0x3)) {
          if (local_34 == (ASN1_ITEM *)0x1) goto LAB_005602d8;
          goto LAB_005603d0;
        }
LAB_00560354:
        pAVar15 = (ASN1_ITEM *)0x0;
        unaff_s0 = (ASN1_ITEM *)(*pcVar22)(*piVar3);
        goto LAB_00560058;
      }
      if (local_34 == (ASN1_ITEM *)&DAT_0000000a) goto LAB_00560354;
      if ((int)local_34 < 0xb) {
        if (local_34 == (ASN1_ITEM *)&DAT_00000006) {
          unaff_s0 = *(ASN1_ITEM **)(*piVar3 + 0xc);
          goto LAB_00560068;
        }
      }
      else if ((local_34 == (ASN1_ITEM *)0x102) || (local_34 == (ASN1_ITEM *)0x10a))
      goto LAB_00560354;
LAB_005603d0:
      pAVar15 = (ASN1_ITEM *)param_3->size;
      if ((pAVar15 != (ASN1_ITEM *)&DAT_00000800) ||
         (((uint)((ASN1_ITEM **)*piVar3)[3] & 0x10) == 0)) {
        unaff_s0 = *(ASN1_ITEM **)*piVar3;
        goto LAB_00560058;
      }
      unaff_s7 = (ASN1_ITEM *)&SUB_00000002;
      if ((long *)0x1 < &local_34[-1].tcount) {
        unaff_s0 = (ASN1_ITEM *)&SUB_fffffffe;
        goto LAB_00560068;
      }
      unaff_s1 = (ASN1_ITEM *)0x0;
LAB_00560294:
      unaff_s7 = (ASN1_ITEM *)&SUB_00000002;
      unaff_s0 = (ASN1_ITEM *)0x0;
LAB_00560088:
      if (param_4 == (ASN1_ITEM *)0xffffffff) {
        param_4 = pAVar2;
      }
      if (param_2 != (ASN1_ITEM *)0x0) {
        if (unaff_s1 != (ASN1_ITEM *)0x0) {
          pAVar15 = unaff_s7;
          pAVar17 = unaff_s0;
          pAVar6 = param_4;
          ASN1_put_object((uchar **)param_2,(int)unaff_s7,(int)unaff_s0,(int)param_4,param_5);
        }
        pAVar2 = *(ASN1_ITEM **)param_2;
        local_30 = pAVar2;
        if (param_3->funcs == (void *)0x0) {
LAB_005601a0:
          if (param_3->itype == '\0') {
            iVar19 = param_3->utype;
            if (iVar19 == 1) goto LAB_005601c8;
            ppAVar7 = (ASN1_ITEM **)*param_1;
            if (ppAVar7 != (ASN1_ITEM **)0x0) goto LAB_005602b4;
          }
          else {
            ppAVar7 = (ASN1_ITEM **)*param_1;
            pAVar15 = (ASN1_ITEM *)&DAT_00000005;
            if (ppAVar7 != (ASN1_ITEM **)0x0) {
              if (param_3->itype == '\x05') {
                local_34 = ppAVar7[1];
              }
              else {
                iVar19 = param_3->utype;
LAB_005602b4:
                pAVar15 = (ASN1_ITEM *)0xfffffffc;
                if (iVar19 == -4) {
                  local_34 = *ppAVar7;
                  param_1 = (int *)(ppAVar7 + 1);
                }
              }
LAB_005601c8:
              if (local_34 != (ASN1_ITEM *)&DAT_00000005) {
                if ((int)local_34 < 6) {
                  if (local_34 == (ASN1_ITEM *)&SUB_00000002) {
LAB_005604c4:
                    if (pAVar2 == (ASN1_ITEM *)0x0) {
                      pAVar15 = (ASN1_ITEM *)0x0;
                    }
                    else {
                      pAVar15 = (ASN1_ITEM *)&local_30;
                    }
                    i2c_ASN1_INTEGER((ASN1_INTEGER *)*param_1,(uchar **)pAVar15);
                    goto joined_r0x00560234;
                  }
                  if (local_34 == (ASN1_ITEM *)0x3) {
                    if (pAVar2 == (ASN1_ITEM *)0x0) {
                      pAVar15 = (ASN1_ITEM *)0x0;
                    }
                    else {
                      pAVar15 = (ASN1_ITEM *)&local_30;
                    }
                    i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*param_1,(uchar **)pAVar15);
                    goto joined_r0x00560234;
                  }
                  if (local_34 != (ASN1_ITEM *)0x1) goto LAB_00560200;
                  pAVar10 = (ASN1_INTEGER *)*param_1;
                  if (pAVar10 == (ASN1_INTEGER *)0xffffffff) goto joined_r0x00560234;
                  pAVar15 = (ASN1_ITEM *)param_3->utype;
                  if (pAVar15 != (ASN1_ITEM *)0xfffffffc) {
                    if (pAVar10 == (ASN1_INTEGER *)0x0) {
                      if (param_3->size != 0) goto LAB_0056041c;
                    }
                    else if (param_3->size < 1) goto LAB_0056041c;
                    goto joined_r0x00560234;
                  }
LAB_0056041c:
                  local_35 = (char)pAVar10;
                  if (pAVar2 == (ASN1_ITEM *)0x0) goto joined_r0x00560234;
                  pAVar17 = (ASN1_ITEM *)0x1;
                  pAVar15 = (ASN1_ITEM *)&local_35;
                }
                else {
                  if (local_34 == (ASN1_ITEM *)&DAT_0000000a) goto LAB_005604c4;
                  if ((int)local_34 < 0xb) {
                    if (local_34 != (ASN1_ITEM *)&DAT_00000006) goto LAB_00560200;
                    pAVar15 = (ASN1_ITEM *)((ASN1_INTEGER *)*param_1)[1].length;
                    pAVar17 = (ASN1_ITEM *)((ASN1_INTEGER *)*param_1)->flags;
                  }
                  else {
                    if ((local_34 == (ASN1_ITEM *)0x102) || (local_34 == (ASN1_ITEM *)0x10a))
                    goto LAB_005604c4;
LAB_00560200:
                    pAVar15 = (ASN1_ITEM *)param_3->size;
                    pAVar10 = (ASN1_INTEGER *)*param_1;
                    if ((pAVar15 == (ASN1_ITEM *)&DAT_00000800) && ((pAVar10->flags & 0x10U) != 0))
                    {
                      if (pAVar2 != (ASN1_ITEM *)0x0) {
                        pAVar10->data = (uchar *)pAVar2;
                        pAVar10->length = 0;
                      }
                      goto joined_r0x00560234;
                    }
                    pAVar15 = (ASN1_ITEM *)pAVar10->data;
                    pAVar17 = (ASN1_ITEM *)pAVar10->length;
                  }
                  if ((pAVar2 == (ASN1_ITEM *)0x0) || (pAVar17 == (ASN1_ITEM *)0x0))
                  goto joined_r0x00560234;
                }
                (*(code *)PTR_memcpy_006aabf4)(pAVar2);
              }
            }
          }
        }
        else {
          pcVar22 = *(code **)((int)param_3->funcs + 0x18);
          pAVar17 = (ASN1_ITEM *)&local_34;
          if (pcVar22 == (code *)0x0) goto LAB_005601a0;
          pAVar6 = param_3;
          (*pcVar22)(param_1);
          pAVar15 = pAVar2;
        }
joined_r0x00560234:
        if (unaff_s7 == (ASN1_ITEM *)0x0) {
          *(ASN1_ITEM **)param_2 =
               (ASN1_ITEM *)(&unaff_s0->itype + (int)&(*(ASN1_ITEM **)param_2)->itype);
        }
        else {
          ASN1_put_eoc((uchar **)param_2);
        }
      }
      pAVar2 = unaff_s0;
      if (unaff_s1 != (ASN1_ITEM *)0x0) {
        pAVar15 = unaff_s0;
        pAVar17 = param_4;
        pAVar2 = (ASN1_ITEM *)ASN1_object_size((int)unaff_s7,(int)unaff_s0,(int)param_4);
      }
    }
  }
  else {
    pcVar22 = *(code **)((int)param_3->funcs + 0x18);
    pAVar15 = (ASN1_ITEM *)0x0;
    if (pcVar22 == (code *)0x0) goto LAB_00560134;
    pAVar17 = (ASN1_ITEM *)&local_34;
    pAVar6 = param_3;
    unaff_s0 = (ASN1_ITEM *)(*pcVar22)();
LAB_00560058:
    pAVar2 = local_34;
    if ((long *)0x1 < &local_34[-1].tcount) goto LAB_00560068;
    unaff_s1 = (ASN1_ITEM *)0x0;
    if (unaff_s0 != (ASN1_ITEM *)0xffffffff) {
LAB_00560078:
      if (unaff_s0 == (ASN1_ITEM *)&SUB_fffffffe) goto LAB_00560294;
      unaff_s7 = (ASN1_ITEM *)0x0;
      goto LAB_00560088;
    }
LAB_0056012c:
    pAVar2 = (ASN1_ITEM *)0x0;
  }
LAB_005600ec:
  if (local_2c == *(ASN1_TEMPLATE **)tt) {
    return pAVar2;
  }
  pcStack_5c = asn1_ex_i2c;
  pAVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  AStack_c0.offset = (ulong)PTR___stack_chk_guard_006aabf0;
  auStack_6d._1_4_ = *(ASN1_TEMPLATE **)PTR___stack_chk_guard_006aabf0;
  AStack_c0.field_name = &unaff_s1->itype;
  pAStack_74 = pAVar15;
  pAStack_64 = unaff_s0;
  pAStack_60 = unaff_s1;
  if ((pAVar6->funcs != (void *)0x0) &&
     (pcVar22 = *(code **)((int)pAVar6->funcs + 0x18), pcVar22 != (code *)0x0)) {
    pAVar4 = (ASN1_ITEM *)(*pcVar22)();
    pAVar2 = pAVar15;
    goto LAB_005605bc;
  }
  pAVar2 = pAVar15;
  if (pAVar6->itype != '\0') {
    ppuVar13 = (uchar **)pAVar12->flags;
    if (ppuVar13 != (uchar **)0x0) {
      pAVar2 = (ASN1_ITEM *)&DAT_00000005;
      if (pAVar6->itype != '\x05') {
        iVar19 = pAVar6->utype;
        goto LAB_00560600;
      }
      puVar11 = ppuVar13[1];
      *(uchar **)pAVar17 = puVar11;
      goto LAB_00560620;
    }
    goto LAB_005607a8;
  }
  iVar19 = pAVar6->utype;
  if (iVar19 != 1) {
    ppuVar13 = (uchar **)pAVar12->flags;
    if (ppuVar13 == (uchar **)0x0) goto LAB_005607a8;
LAB_00560600:
    pAVar2 = (ASN1_ITEM *)0xfffffffc;
    if (iVar19 == -4) {
      puVar11 = *ppuVar13;
      pAVar12 = (ASN1_TEMPLATE *)(ppuVar13 + 1);
      *(uchar **)pAVar17 = puVar11;
      goto LAB_00560620;
    }
  }
  puVar11 = *(uchar **)pAVar17;
LAB_00560620:
  if (puVar11 == &DAT_00000005) {
LAB_00560680:
    pAVar4 = (ASN1_ITEM *)0x0;
  }
  else if ((int)puVar11 < 6) {
    if (puVar11 == &SUB_00000002) {
LAB_00560720:
      if (pAVar15 == (ASN1_ITEM *)0x0) {
        pAVar2 = (ASN1_ITEM *)0x0;
      }
      else {
        pAVar2 = (ASN1_ITEM *)&pAStack_74;
      }
      pAVar4 = (ASN1_ITEM *)i2c_ASN1_INTEGER((ASN1_INTEGER *)pAVar12->flags,(uchar **)pAVar2);
      goto LAB_005605bc;
    }
    if (puVar11 == (uchar *)0x3) {
      if (pAVar15 == (ASN1_ITEM *)0x0) {
        pAVar2 = (ASN1_ITEM *)0x0;
      }
      else {
        pAVar2 = (ASN1_ITEM *)&pAStack_74;
      }
      pAVar4 = (ASN1_ITEM *)i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)pAVar12->flags,(uchar **)pAVar2);
      goto LAB_005605bc;
    }
    if (puVar11 != (uchar *)0x1) goto LAB_00560654;
    puVar11 = (uchar *)pAVar12->flags;
    if (puVar11 == (uchar *)0xffffffff) {
LAB_005607a8:
      pAVar4 = (ASN1_ITEM *)0xffffffff;
      goto LAB_005605bc;
    }
    pAVar2 = (ASN1_ITEM *)pAVar6->utype;
    if (pAVar2 != (ASN1_ITEM *)0xfffffffc) {
      if (puVar11 == (uchar *)0x0) {
        if (pAVar6->size == 0) goto LAB_005607a8;
      }
      else {
        pAVar4 = (ASN1_ITEM *)0xffffffff;
        if (0 < pAVar6->size) goto LAB_005605bc;
      }
    }
    pAVar4 = (ASN1_ITEM *)0x1;
    auStack_6d[0] = (char)puVar11;
    if (pAVar15 == (ASN1_ITEM *)0x0) goto LAB_005605bc;
    pAVar4 = (ASN1_ITEM *)0x1;
    pAVar2 = (ASN1_ITEM *)auStack_6d;
LAB_00560788:
    pAVar17 = pAVar4;
    (*(code *)PTR_memcpy_006aabf4)();
    AStack_c0.field_name = &pAVar4->itype;
  }
  else {
    if (puVar11 == &DAT_0000000a) goto LAB_00560720;
    if ((int)puVar11 < 0xb) {
      if (puVar11 != &DAT_00000006) goto LAB_00560654;
      pAVar2 = *(ASN1_ITEM **)((uchar *)pAVar12->flags + 0x10);
      pAVar4 = *(ASN1_ITEM **)((uchar *)pAVar12->flags + 0xc);
LAB_0056066c:
      AStack_c0.field_name = &pAVar4->itype;
      if (pAVar15 != (ASN1_ITEM *)0x0) {
        pAVar17 = pAVar4;
        if (pAVar4 == (ASN1_ITEM *)0x0) goto LAB_00560680;
        goto LAB_00560788;
      }
    }
    else {
      if ((puVar11 == (uchar *)0x102) || (puVar11 == (uchar *)0x10a)) goto LAB_00560720;
LAB_00560654:
      ppAVar7 = (ASN1_ITEM **)pAVar12->flags;
      if (((undefined *)pAVar6->size != &DAT_00000800) || (((uint)ppAVar7[3] & 0x10) == 0)) {
        pAVar2 = ppAVar7[2];
        pAVar4 = *ppAVar7;
        goto LAB_0056066c;
      }
      if (pAVar15 == (ASN1_ITEM *)0x0) {
        pAVar4 = (ASN1_ITEM *)&SUB_fffffffe;
      }
      else {
        ppAVar7[2] = pAVar15;
        pAVar4 = (ASN1_ITEM *)&SUB_fffffffe;
        *ppAVar7 = (ASN1_ITEM *)0x0;
      }
    }
  }
LAB_005605bc:
  if (auStack_6d._1_4_ == *(ASN1_TEMPLATE **)AStack_c0.offset) {
    return pAVar4;
  }
  pAVar12 = auStack_6d._1_4_;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  AStack_c0.item = (ASN1_ITEM_EXP *)tt;
  uVar5 = (uint)pAVar2->itype;
  pvVar16 = pAVar2->funcs;
  AStack_c0.tag = *(long *)PTR___stack_chk_guard_006aabf0;
  pAStack_ac = param_3;
  pAStack_a8 = param_4;
  pAStack_a4 = param_2;
  piStack_a0 = param_1;
  pAStack_9c = unaff_s7;
  if (uVar5 != 0) {
    pAVar14 = (ASN1_VALUE *)pAVar12->flags;
    if (pAVar14 == (ASN1_VALUE *)0x0) goto switchD_005608d8_caseD_7;
    if ((pvVar16 == (void *)0x0) ||
       (pcVar22 = *(code **)((int)pvVar16 + 0x10), pcVar22 == (code *)0x0)) goto LAB_005608b8;
    switch(uVar5 & 0xff) {
    default:
      goto switchD_005608d8_caseD_7;
    case 1:
      iStack_cc = 1;
      break;
    case 2:
      iVar19 = (*pcVar22)(6,pAVar12,pAVar2,0);
      if (iVar19 == 0) goto switchD_005608d8_caseD_7;
      iVar19 = asn1_get_choice_selector((ASN1_VALUE **)pAVar12,pAVar2);
      if ((iVar19 < 0) || (pAVar2->tcount <= iVar19)) {
        (*pcVar22)(7,pAVar12,pAVar2,0);
        pAVar15 = (ASN1_ITEM *)0x0;
        goto LAB_00560908;
      }
      goto LAB_00560e18;
    case 3:
      goto switchD_0056089c_caseD_3;
    case 4:
      goto switchD_005608d8_caseD_4;
    case 5:
      goto switchD_005608d8_caseD_5;
    case 6:
      goto switchD_0056089c_caseD_6;
    }
    goto LAB_005609e0;
  }
  if ((pvVar16 == (void *)0x0) || (*(int *)((int)pvVar16 + 0x10) != 0)) {
switchD_005608d8_caseD_0:
    pAVar20 = pAVar2->templates;
    if (pAVar20 == (ASN1_TEMPLATE *)0x0) {
      pAVar15 = (ASN1_ITEM *)asn1_i2d_ex_primitive(pAVar12,0,pAVar2,0xffffffff,pAVar17);
      goto LAB_00560908;
    }
    param_4 = (ASN1_ITEM *)pAVar20->flags;
    uVar5 = 0;
    if (((uint)param_4 & 0x18) == 0) {
      tag = (undefined *)0xffffffff;
    }
    else {
      tag = (undefined *)pAVar20->tag;
      uVar5 = (uint)param_4 & 0xc0;
    }
    pAVar2 = (ASN1_ITEM *)((uint)pAVar17 & 0xffffff3f);
    if (((uint)param_4 & 0x800) == 0) {
      pAVar6 = (ASN1_ITEM *)0x1;
    }
    else {
      pAVar6 = (ASN1_ITEM *)&SUB_00000002;
      if (((uint)pAVar17 & 0x800) == 0) {
        pAVar6 = (ASN1_ITEM *)0x1;
      }
    }
    pAVar17 = pAVar6;
    if (((uint)param_4 & 6) == 0) {
      param_4 = (ASN1_ITEM *)((uint)param_4 & 0x10);
      if (param_4 == (ASN1_ITEM *)0x0) {
        pAVar15 = (ASN1_ITEM *)
                  ASN1_item_ex_i2d((ASN1_VALUE **)pAVar12,(uchar **)0x0,pAVar20->item,(int)tag,
                                   (uint)pAVar2 | uVar5);
        goto LAB_00560908;
      }
      pAVar15 = (ASN1_ITEM *)ASN1_item_ex_i2d_constprop_0(pAVar12,pAVar20->item,pAVar2);
      if (pAVar15 != (ASN1_ITEM *)0x0) goto LAB_00560ba0;
    }
    else {
      pAVar14 = (ASN1_VALUE *)pAVar12->flags;
      if (pAVar14 != (ASN1_VALUE *)0x0) {
        if (((uint)param_4 & 2) == 0) {
          if (tag == (undefined *)0xffffffff) {
            puStack_e4 = &SUB_00000010;
          }
          else {
            puStack_e4 = &SUB_00000010;
            if (((uint)param_4 & 0x10) == 0) {
              puStack_e4 = tag;
            }
          }
        }
        else if (tag == (undefined *)0xffffffff) {
          puStack_e4 = &DAT_00000011;
        }
        else {
          puStack_e4 = &DAT_00000011;
          if (((uint)param_4 & 0x10) == 0) {
            puStack_e4 = tag;
          }
        }
        pAStack_e8 = (ASN1_TEMPLATE *)((uint)param_4 & 0x10);
        tt = (ASN1_TEMPLATE *)0x0;
        pAVar12 = &AStack_c0;
        for (param_4 = (ASN1_ITEM *)0x0; iVar19 = (*(code *)PTR_sk_num_006a7f2c)(pAVar14),
            (int)param_4 < iVar19; param_4 = (ASN1_ITEM *)&param_4->field_0x1) {
          AStack_c0.flags = (*(code *)PTR_sk_value_006a7f24)(pAVar14,param_4);
          iVar19 = ASN1_item_ex_i2d_constprop_0(pAVar12,pAVar20->item,pAVar2);
          tt = (ASN1_TEMPLATE *)((int)&tt->flags + iVar19);
        }
        pAVar15 = (ASN1_ITEM *)ASN1_object_size((int)pAVar6,(int)tt,(int)puStack_e4);
        if (pAStack_e8 == (ASN1_TEMPLATE *)0x0) goto LAB_00560908;
LAB_00560ba0:
        pAVar15 = (ASN1_ITEM *)ASN1_object_size((int)pAVar6,(int)pAVar15,(int)tag);
        goto LAB_00560908;
      }
    }
    goto switchD_005608d8_caseD_7;
  }
LAB_005608b8:
  switch(uVar5 & 0xff) {
  case 0:
    goto switchD_005608d8_caseD_0;
  case 1:
    pcVar22 = (code *)0x0;
    iStack_cc = 1;
    goto LAB_005609e0;
  case 2:
    iVar19 = asn1_get_choice_selector((ASN1_VALUE **)pAVar12,pAVar2);
    if ((-1 < iVar19) && (iVar19 < pAVar2->tcount)) {
LAB_00560e18:
      pAVar20 = pAVar2->templates;
      ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pAVar12,pAVar20 + iVar19);
      pAVar15 = (ASN1_ITEM *)asn1_template_ex_i2d(ppAVar9,0,pAVar20 + iVar19,0xffffffff,pAVar17);
      goto LAB_00560908;
    }
    break;
  case 3:
    pAVar14 = (ASN1_VALUE *)pAVar12->flags;
switchD_0056089c_caseD_3:
    pAVar15 = (ASN1_ITEM *)(**(code **)((int)pvVar16 + 0xc))(pAVar14,0);
    goto LAB_00560908;
  case 4:
switchD_005608d8_caseD_4:
    pAVar15 = (ASN1_ITEM *)(**(code **)((int)pvVar16 + 0x14))(pAVar12,0,pAVar2,0xffffffff,pAVar17);
    goto LAB_00560908;
  case 5:
switchD_005608d8_caseD_5:
    AStack_c0.flags = pAVar2->utype;
    pAVar15 = (ASN1_ITEM *)asn1_ex_i2c((ASN1_VALUE **)pAVar12,(uchar *)0x0,(int *)&AStack_c0,pAVar2)
    ;
    if (pAVar15 != (ASN1_ITEM *)0xffffffff) {
      if (pAVar15 == (ASN1_ITEM *)&SUB_fffffffe) {
        iVar19 = 2;
        pAVar15 = (ASN1_ITEM *)0x0;
      }
      else {
        iVar19 = 0;
      }
      if (AStack_c0.flags - 0x10 < 2 || AStack_c0.flags == 0xfffffffd) goto LAB_00560908;
      pAVar15 = (ASN1_ITEM *)ASN1_object_size(iVar19,(int)pAVar15,AStack_c0.flags);
      goto LAB_00560908;
    }
    break;
  case 6:
    pcVar22 = (code *)0x0;
switchD_0056089c_caseD_6:
    iStack_cc = 1;
    if (((uint)pAVar17 & 0x800) != 0) {
      iStack_cc = 2;
    }
LAB_005609e0:
    puStack_e4 = (undefined *)
                 asn1_enc_restore((int *)&pAStack_c4,(uchar **)0x0,(ASN1_VALUE **)pAVar12,pAVar2);
    if (-1 < (int)puStack_e4) {
      pAVar15 = pAStack_c4;
      if (puStack_e4 != (undefined *)0x0) goto LAB_00560908;
      pAStack_c4 = (ASN1_ITEM *)0x0;
      if ((pcVar22 == (code *)0x0) || (iVar19 = (*pcVar22)(6,pAVar12,pAVar2,0), iVar19 != 0)) {
        pAStack_e8 = pAVar2->templates;
        if (pAVar2->tcount < 1) goto LAB_00560d54;
        iStack_d8 = 2;
        if (((uint)pAVar17 & 0x800) == 0) {
          iStack_d8 = 1;
        }
        param_4 = (ASN1_ITEM *)((uint)pAVar17 & 0xffffff3f);
        goto LAB_00560c10;
      }
    }
  }
switchD_005608d8_caseD_7:
  pAVar15 = (ASN1_ITEM *)0x0;
LAB_00560908:
  if (AStack_c0.tag == *(int *)puVar1) {
    return pAVar15;
  }
  pAStack_d4 = (ASN1_ITEM *)(*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00560f4c:
  iStack_d0 = 0x10;
LAB_00560ca4:
  iVar19 = 0;
  for (iVar21 = 0; iVar8 = (*(code *)PTR_sk_num_006a7f2c)(pAVar17), iVar21 < iVar8;
      iVar21 = iVar21 + 1) {
    AStack_c0.flags = (*(code *)PTR_sk_value_006a7f24)(pAVar17,iVar21);
    iVar8 = ASN1_item_ex_i2d_constprop_0(&AStack_c0,tt->item,param_4);
    iVar19 = iVar19 + iVar8;
  }
  pAVar17 = (ASN1_ITEM *)ASN1_object_size(iStack_dc,iVar19,iStack_d0);
  pAVar15 = pAVar17;
  do {
    if (pAStack_d4 != (ASN1_ITEM *)0x0) {
      pAVar17 = (ASN1_ITEM *)ASN1_object_size(iStack_dc,(int)pAVar15,iStack_e0);
    }
    while( true ) {
      while( true ) {
        puStack_e4 = puStack_e4 + 1;
        pAStack_e8 = pAStack_e8 + 1;
        pAStack_c4 = (ASN1_ITEM *)(&pAStack_c4->itype + (int)&pAVar17->itype);
        if (pAVar2->tcount <= (int)puStack_e4) goto LAB_00560d54;
LAB_00560c10:
        tt = asn1_do_adb((ASN1_VALUE **)pAVar12,pAStack_e8,1);
        if (tt == (ASN1_TEMPLATE *)0x0) goto switchD_005608d8_caseD_7;
        ppAVar7 = (ASN1_ITEM **)asn1_get_field_ptr((ASN1_VALUE **)pAVar12,tt);
        uVar5 = tt->flags;
        if ((uVar5 & 0x18) == 0) {
          uVar18 = 0;
          iStack_e0 = -1;
        }
        else {
          iStack_e0 = tt->tag;
          uVar18 = uVar5 & 0xc0;
        }
        pAVar17 = (ASN1_ITEM *)(uVar5 & 6);
        iStack_dc = 1;
        if ((uVar5 & 0x800) != 0) {
          iStack_dc = iStack_d8;
        }
        if (pAVar17 == (ASN1_ITEM *)0x0) break;
        pAVar17 = *ppAVar7;
        if (pAVar17 != (ASN1_ITEM *)0x0) {
          if ((uVar5 & 2) == 0) {
            pAStack_d4 = (ASN1_ITEM *)(uVar5 & 0x10);
            if (iStack_e0 == -1) goto LAB_00560f4c;
            iStack_d0 = 0x10;
            if (pAStack_d4 == (ASN1_ITEM *)0x0) {
              iStack_d0 = iStack_e0;
            }
          }
          else {
            pAStack_d4 = (ASN1_ITEM *)(uVar5 & 0x10);
            if (iStack_e0 == -1) {
              iStack_d0 = 0x11;
            }
            else {
              iStack_d0 = 0x11;
              if (pAStack_d4 == (ASN1_ITEM *)0x0) {
                iStack_d0 = iStack_e0;
              }
            }
          }
          goto LAB_00560ca4;
        }
        pAVar17 = (ASN1_ITEM *)0x0;
      }
      if ((uVar5 & 0x10) != 0) break;
      pAVar17 = (ASN1_ITEM *)
                ASN1_item_ex_i2d((ASN1_VALUE **)ppAVar7,(uchar **)0x0,tt->item,iStack_e0,
                                 (uint)param_4 | uVar18);
    }
    pAVar15 = (ASN1_ITEM *)ASN1_item_ex_i2d_constprop_0(ppAVar7,tt->item,param_4);
    pAStack_d4 = pAVar15;
  } while( true );
LAB_00560d54:
  pAVar15 = (ASN1_ITEM *)ASN1_object_size(iStack_cc,(int)pAStack_c4,0x10);
  goto LAB_00560908;
}

