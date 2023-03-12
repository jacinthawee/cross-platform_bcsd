
void ASN1_item_ex_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  ASN1_TEMPLATE **ppAVar1;
  long *plVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  ASN1_ITEM *pval_00;
  ASN1_ITEM *pAVar8;
  ASN1_ITEM *unaff_s0;
  ASN1_ITEM *unaff_s1;
  ASN1_ITEM *unaff_s2;
  ASN1_ITEM *unaff_s3;
  undefined *unaff_s4;
  ASN1_ITEM_EXP *unaff_s5;
  ASN1_ITEM *unaff_s6;
  ASN1_ITEM *unaff_s7;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *unaff_s8;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  do {
    pval_00 = (ASN1_ITEM *)pval;
    puVar3 = PTR___stack_chk_guard_006a9ae8;
    puVar9 = &_gp;
    *(undefined **)((int)register0x00000074 + -0x18) = unaff_s4;
    *(ASN1_ITEM **)((int)register0x00000074 + -0x20) = unaff_s2;
    pval = (ASN1_VALUE **)it->funcs;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(undefined **)((int)register0x00000074 + -8) = unaff_s8;
    *(ASN1_ITEM **)((int)register0x00000074 + -0xc) = unaff_s7;
    *(ASN1_ITEM **)((int)register0x00000074 + -0x10) = unaff_s6;
    *(ASN1_ITEM_EXP **)((int)register0x00000074 + -0x14) = unaff_s5;
    *(ASN1_ITEM **)((int)register0x00000074 + -0x1c) = unaff_s3;
    *(ASN1_ITEM **)((int)register0x00000074 + -0x24) = unaff_s1;
    *(ASN1_ITEM **)((int)register0x00000074 + -0x28) = unaff_s0;
    *(undefined **)((int)register0x00000074 + -0x40) = &_gp;
    *(undefined4 *)((int)register0x00000074 + 8) = 0;
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8
    ;
    pAVar8 = it;
    if (pval_00 != (ASN1_ITEM *)0x0) {
      uVar4 = (uint)it->itype;
      unaff_s1 = it;
      if (uVar4 == 0) {
        if ((ASN1_ITEM *)pval == (ASN1_ITEM *)0x0) {
switchD_0055c088_caseD_0:
          unaff_s3 = (ASN1_ITEM *)it->templates;
          if (unaff_s3 == (ASN1_ITEM *)0x0) goto LAB_0055be5c;
          unaff_s0 = (ASN1_ITEM *)0x0;
          if ((*(uint *)unaff_s3 & 6) == 0) {
            pAVar8 = (ASN1_ITEM *)unaff_s3->funcs;
            pval = (ASN1_VALUE **)pval_00;
            asn1_item_combine_free(pval_00,pAVar8,*(uint *)unaff_s3 & 0x400);
            puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
          }
          else {
            unaff_s1 = *(ASN1_ITEM **)pval_00;
            unaff_s5 = (ASN1_ITEM_EXP *)((int)register0x00000074 + -0x30);
            while( true ) {
              iVar6 = (**(code **)(puVar9 + -0x7fb4))(unaff_s1);
              if (iVar6 <= (int)unaff_s0) break;
              uVar5 = (**(code **)(*(int *)((int)register0x00000074 + -0x40) + -0x7fbc))
                                (unaff_s1,unaff_s0);
              *(undefined4 *)((int)register0x00000074 + -0x30) = uVar5;
              it = (ASN1_ITEM *)unaff_s3->funcs;
              asn1_item_combine_free(unaff_s5,it,0);
              puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
              unaff_s0 = (ASN1_ITEM *)&unaff_s0->field_0x1;
            }
            pval = (ASN1_VALUE **)unaff_s1;
            (**(code **)(*(int *)((int)register0x00000074 + -0x40) + -0x7f60))();
            puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
            *(undefined4 *)pval_00 = 0;
            pAVar8 = it;
          }
        }
        else {
LAB_0055bd0c:
          unaff_s5 = *(ASN1_ITEM_EXP **)((int)pval + 0x10);
          if (unaff_s5 == (ASN1_ITEM_EXP *)0x0) {
            switch(uVar4 & 0xff) {
            case 0:
              goto switchD_0055c088_caseD_0;
            case 1:
            case 6:
switchD_0055bdc8_caseD_1:
              pAVar8 = (ASN1_ITEM *)0xffffffff;
              pval = (ASN1_VALUE **)pval_00;
              iVar6 = asn1_do_lock((ASN1_VALUE **)pval_00,-1,it);
              puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
              if (iVar6 < 1) {
                unaff_s5 = (ASN1_ITEM_EXP *)0x0;
                pAVar8 = it;
                asn1_enc_free((ASN1_VALUE **)pval_00,it);
                iVar6 = it->tcount;
                puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                pval = (ASN1_VALUE **)(iVar6 * 0x10);
                unaff_s6 = (ASN1_ITEM *)(it->templates + iVar6 + -1);
                if (iVar6 < 1) {
                  iVar6 = *(int *)((int)register0x00000074 + 8);
                }
                else {
LAB_0055bf80:
                  unaff_s8 = (undefined *)((int)register0x00000074 + -0x30);
                  *(undefined4 *)((int)register0x00000074 + -0x38) = 0;
                  do {
                    pval = (ASN1_VALUE **)pval_00;
                    pAVar8 = unaff_s6;
                    unaff_s3 = (ASN1_ITEM *)
                               asn1_do_adb((ASN1_VALUE **)pval_00,(ASN1_TEMPLATE *)unaff_s6,0);
                    puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                    if (unaff_s3 != (ASN1_ITEM *)0x0) {
                      pAVar8 = unaff_s3;
                      pval = asn1_get_field_ptr((ASN1_VALUE **)pval_00,(ASN1_TEMPLATE *)unaff_s3);
                      uVar4 = *(uint *)unaff_s3;
                      puVar10 = *(undefined **)((int)register0x00000074 + -0x40);
                      *(ASN1_VALUE ***)((int)register0x00000074 + -0x34) = pval;
                      if ((uVar4 & 6) == 0) {
                        pAVar8 = (ASN1_ITEM *)unaff_s3->funcs;
                        asn1_item_combine_free(pval,pAVar8,uVar4 & 0x400);
                        puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                      }
                      else {
                        unaff_s0 = (ASN1_ITEM *)*pval;
                        unaff_s7 = (ASN1_ITEM *)0x0;
                        while( true ) {
                          iVar6 = (**(code **)(puVar10 + -0x7fb4))(unaff_s0);
                          if (iVar6 <= (int)unaff_s7) break;
                          uVar5 = (**(code **)(*(int *)((int)register0x00000074 + -0x40) + -0x7fbc))
                                            (unaff_s0,unaff_s7);
                          *(undefined4 *)((int)register0x00000074 + -0x30) = uVar5;
                          pAVar8 = (ASN1_ITEM *)unaff_s3->funcs;
                          asn1_item_combine_free(unaff_s8,pAVar8,0);
                          puVar10 = *(undefined **)((int)register0x00000074 + -0x40);
                          unaff_s7 = (ASN1_ITEM *)&unaff_s7->field_0x1;
                        }
                        pval = (ASN1_VALUE **)unaff_s0;
                        (**(code **)(*(int *)((int)register0x00000074 + -0x40) + -0x7f60))();
                        puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                        **(undefined4 **)((int)register0x00000074 + -0x34) = 0;
                      }
                    }
                    iVar7 = *(int *)((int)register0x00000074 + -0x38);
                    unaff_s6 = (ASN1_ITEM *)&unaff_s6[-1].templates;
                    iVar6 = it->tcount;
                    *(int *)((int)register0x00000074 + -0x38) = iVar7 + 1;
                  } while (iVar7 + 1 < iVar6);
                  if (unaff_s5 != (ASN1_ITEM_EXP *)0x0) goto LAB_0055be20;
                  iVar6 = *(int *)((int)register0x00000074 + 8);
                }
                goto LAB_0055be3c;
              }
              break;
            case 2:
switchD_0055bdc8_caseD_2:
              pval = (ASN1_VALUE **)pval_00;
              iVar6 = asn1_get_choice_selector((ASN1_VALUE **)pval_00,it);
              puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
              if ((-1 < iVar6) && (unaff_s5 = (ASN1_ITEM_EXP *)0x0, iVar6 < it->tcount)) {
LAB_0055c118:
                unaff_s6 = (ASN1_ITEM *)(it->templates + iVar6);
                pAVar8 = unaff_s6;
                unaff_s7 = (ASN1_ITEM *)
                           asn1_get_field_ptr((ASN1_VALUE **)pval_00,(ASN1_TEMPLATE *)unaff_s6);
                puVar11 = *(undefined **)((int)register0x00000074 + -0x40);
                if ((*(uint *)unaff_s6 & 6) == 0) {
                  pAVar8 = (ASN1_ITEM *)unaff_s6->funcs;
                  pval = (ASN1_VALUE **)unaff_s7;
                  asn1_item_combine_free(unaff_s7,pAVar8,*(uint *)unaff_s6 & 0x400);
                  puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                }
                else {
                  unaff_s3 = *(ASN1_ITEM **)unaff_s7;
                  unaff_s8 = (undefined *)((int)register0x00000074 + -0x30);
                  unaff_s0 = (ASN1_ITEM *)0x0;
                  while( true ) {
                    iVar6 = (**(code **)(puVar11 + -0x7fb4))(unaff_s3);
                    if (iVar6 <= (int)unaff_s0) break;
                    uVar5 = (**(code **)(*(int *)((int)register0x00000074 + -0x40) + -0x7fbc))
                                      (unaff_s3,unaff_s0);
                    *(undefined4 *)((int)register0x00000074 + -0x30) = uVar5;
                    pAVar8 = (ASN1_ITEM *)unaff_s6->funcs;
                    asn1_item_combine_free(unaff_s8,pAVar8,0);
                    puVar11 = *(undefined **)((int)register0x00000074 + -0x40);
                    unaff_s0 = (ASN1_ITEM *)&unaff_s0->field_0x1;
                  }
                  pval = (ASN1_VALUE **)unaff_s3;
                  (**(code **)(*(int *)((int)register0x00000074 + -0x40) + -0x7f60))();
                  puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                  *(undefined4 *)unaff_s7 = 0;
                }
                if (unaff_s5 != (ASN1_ITEM_EXP *)0x0) goto LAB_0055be20;
              }
LAB_0055be38:
              iVar6 = *(int *)((int)register0x00000074 + 8);
LAB_0055be3c:
              if (iVar6 == 0) {
                pval = *(ASN1_VALUE ***)pval_00;
                (**(code **)(puVar9 + -0x7f58))();
                puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                *(undefined4 *)pval_00 = 0;
              }
              break;
            case 3:
              goto switchD_0055c088_caseD_3;
            case 4:
              goto switchD_0055c088_caseD_4;
            case 5:
              goto LAB_0055be5c;
            }
          }
          else {
            switch(uVar4 & 0xff) {
            case 0:
              goto switchD_0055c088_caseD_0;
            case 1:
            case 6:
              pAVar8 = (ASN1_ITEM *)0xffffffff;
              pval = (ASN1_VALUE **)pval_00;
              iVar6 = asn1_do_lock((ASN1_VALUE **)pval_00,-1,it);
              puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
              if (iVar6 < 1) {
                pval = (ASN1_VALUE **)&SUB_00000002;
                pAVar8 = pval_00;
                iVar6 = (*(code *)unaff_s5)(2,pval_00,it,0);
                puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                if (iVar6 != 2) {
                  asn1_enc_free((ASN1_VALUE **)pval_00,it);
                  unaff_s6 = (ASN1_ITEM *)(it->templates + it->tcount + -1);
                  if (0 < it->tcount) goto LAB_0055bf80;
                  goto LAB_0055be20;
                }
              }
              break;
            case 2:
              pval = (ASN1_VALUE **)&SUB_00000002;
              pAVar8 = pval_00;
              iVar6 = (*(code *)unaff_s5)(2,pval_00,it,0);
              puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
              if (iVar6 != 2) {
                iVar6 = asn1_get_choice_selector((ASN1_VALUE **)pval_00,it);
                if ((-1 < iVar6) && (iVar6 < it->tcount)) goto LAB_0055c118;
LAB_0055be20:
                pval = (ASN1_VALUE **)0x3;
                pAVar8 = pval_00;
                (*(code *)unaff_s5)(3,pval_00,it,0);
                puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
                goto LAB_0055be38;
              }
              break;
            case 3:
switchD_0055c088_caseD_3:
              plVar2 = (long *)((int)pval + 4);
              if ((code *)*plVar2 != (code *)0x0) {
                pval = *(ASN1_VALUE ***)pval_00;
                (*(code *)*plVar2)();
                puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
              }
              break;
            case 4:
switchD_0055c088_caseD_4:
              ppAVar1 = (ASN1_TEMPLATE **)((int)pval + 8);
              if (*ppAVar1 != (ASN1_TEMPLATE *)0x0) {
                pval = (ASN1_VALUE **)pval_00;
                (*(code *)*ppAVar1)();
                puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
              }
              break;
            case 5:
LAB_0055be5c:
              pval = (ASN1_VALUE **)pval_00;
              ASN1_primitive_free((ASN1_VALUE **)pval_00,it);
              puVar9 = *(undefined **)((int)register0x00000074 + -0x40);
            }
          }
        }
      }
      else if (*(int *)pval_00 != 0) {
        if ((ASN1_ITEM *)pval != (ASN1_ITEM *)0x0) goto LAB_0055bd0c;
        switch(uVar4 & 0xff) {
        case 1:
        case 6:
          goto switchD_0055bdc8_caseD_1;
        case 2:
          goto switchD_0055bdc8_caseD_2;
        case 5:
          goto LAB_0055be5c;
        }
      }
    }
    if (*(int *)((int)register0x00000074 + -0x2c) == *(int *)puVar3) {
      return;
    }
    unaff_retaddr = ASN1_item_ex_free;
    (**(code **)(puVar9 + -0x5330))();
    it = pAVar8;
    unaff_s2 = pval_00;
    unaff_s4 = puVar3;
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x50);
  } while( true );
}

