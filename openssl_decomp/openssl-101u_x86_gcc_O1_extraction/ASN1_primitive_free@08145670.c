
void ASN1_primitive_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  code *UNRECOVERED_JUMPTABLE;
  int *piVar1;
  char *pcVar2;
  ASN1_OBJECT *a;
  int iVar3;
  ASN1_OBJECT *a_00;
  ASN1_OBJECT *a_01;
  
  if (it == (ASN1_ITEM *)0x0) {
    piVar1 = (int *)*pval;
    a_00 = (ASN1_OBJECT *)piVar1[1];
    iVar3 = *piVar1;
    pval = (ASN1_VALUE **)(piVar1 + 1);
    if (a_00 == (ASN1_OBJECT *)0x0) {
      return;
    }
    if (iVar3 == 1) {
      piVar1[1] = -1;
      return;
    }
    if (iVar3 < 2) goto LAB_08145709;
    if (iVar3 == 5) goto LAB_081456c5;
    if (iVar3 == 6) goto LAB_081456b9;
  }
  else {
    if ((it->funcs != (void *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)((int)it->funcs + 0xc),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x08145690. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    if (it->itype == '\x05') {
      a_00 = (ASN1_OBJECT *)*pval;
      if (a_00 == (ASN1_OBJECT *)0x0) {
        return;
      }
    }
    else {
      iVar3 = it->utype;
      if (iVar3 == 1) {
        *pval = (ASN1_VALUE *)it->size;
        return;
      }
      a_00 = (ASN1_OBJECT *)*pval;
      if (a_00 == (ASN1_OBJECT *)0x0) {
        return;
      }
      if (iVar3 == 5) goto LAB_081456c5;
      if (iVar3 == 6) {
LAB_081456b9:
        ASN1_OBJECT_free(a_00);
        goto LAB_081456c5;
      }
LAB_08145709:
      if (iVar3 == -4) {
        a_01 = (ASN1_OBJECT *)a_00->ln;
        pcVar2 = a_00->sn;
        if (a_01 != (ASN1_OBJECT *)0x0) {
          if (pcVar2 == (char *)0x1) {
            a_00->ln = (char **)0xffffffff;
          }
          else {
            if ((int)pcVar2 < 2) {
              if (pcVar2 == (char *)0xfffffffc) {
                a = (ASN1_OBJECT *)a_01->ln;
                pcVar2 = a_01->sn;
                if (a != (ASN1_OBJECT *)0x0) {
                  if (pcVar2 == (char *)0x1) {
                    a_01->ln = (char **)0xffffffff;
                  }
                  else {
                    if ((int)pcVar2 < 2) {
                      if (pcVar2 == (char *)0xfffffffc) {
                        ASN1_primitive_free_part_0();
                        CRYPTO_free(a_01->ln);
                      }
                      else {
LAB_0814582c:
                        ASN1_STRING_free((ASN1_STRING *)a);
                      }
                    }
                    else if (pcVar2 != (char *)0x5) {
                      if (pcVar2 != (char *)0x6) goto LAB_0814582c;
                      ASN1_OBJECT_free(a);
                    }
                    a_01->ln = (char **)0x0;
                    a_01 = (ASN1_OBJECT *)a_00->ln;
                  }
                }
                CRYPTO_free(a_01);
              }
              else {
LAB_081457f0:
                ASN1_STRING_free((ASN1_STRING *)a_01);
              }
            }
            else if (pcVar2 != (char *)0x5) {
              if (pcVar2 != (char *)0x6) goto LAB_081457f0;
              ASN1_OBJECT_free(a_01);
            }
            a_00->ln = (char **)0x0;
            a_00 = (ASN1_OBJECT *)*pval;
          }
        }
        CRYPTO_free(a_00);
        goto LAB_081456c5;
      }
    }
  }
  ASN1_STRING_free((ASN1_STRING *)a_00);
  *pval = (ASN1_VALUE *)0x0;
LAB_081456c5:
  *pval = (ASN1_VALUE *)0x0;
  return;
}

