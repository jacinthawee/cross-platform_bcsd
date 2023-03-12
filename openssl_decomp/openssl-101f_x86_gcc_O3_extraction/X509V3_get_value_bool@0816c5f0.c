
/* WARNING: Removing unreachable block (ram,0x0816c6f2) */
/* WARNING: Removing unreachable block (ram,0x0816c774) */

int X509V3_get_value_bool(CONF_VALUE *value,int *asn1_bool)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  pbVar2 = (byte *)value->value;
  bVar6 = pbVar2 == (byte *)0x0;
  if (bVar6) goto LAB_0816c728;
  iVar3 = 5;
  pbVar4 = pbVar2;
  pbVar5 = &DAT_0822ba76;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar6);
  if (bVar6) goto LAB_0816c640;
  iVar3 = 5;
  pbVar4 = pbVar2;
  pbVar5 = &DAT_0822ba81;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar6);
  if ((bVar6) || ((bVar1 = *pbVar2, bVar1 == 0x59 && (pbVar2[1] == 0)))) goto LAB_0816c640;
  if (bVar1 == 0x79) {
    if (pbVar2[1] == 0) goto LAB_0816c640;
    bVar6 = pbVar2[1] < 0x65;
    bVar7 = pbVar2[1] == 0x65;
    if (bVar7) {
      bVar6 = pbVar2[2] < 0x73;
      bVar7 = pbVar2[2] == 0x73;
      if (bVar7) goto LAB_0816c67d;
    }
  }
  else {
    bVar6 = false;
    bVar7 = bVar1 == 0x59;
    if (bVar7) {
      if (pbVar2[1] == 0x45) {
        bVar6 = pbVar2[2] < 0x53;
        bVar7 = pbVar2[2] == 0x53;
        if (bVar7) {
LAB_0816c67d:
          bVar6 = false;
          bVar7 = pbVar2[3] == 0;
          if (bVar7) {
LAB_0816c640:
            *asn1_bool = 0xff;
            return 1;
          }
        }
      }
      else {
        bVar6 = false;
        bVar7 = false;
      }
    }
  }
  iVar3 = 6;
  pbVar4 = pbVar2;
  pbVar5 = (byte *)"FALSE";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar7);
  bVar6 = (!bVar6 && !bVar7) == bVar6;
  if (!bVar6) {
    iVar3 = 6;
    pbVar4 = pbVar2;
    pbVar5 = (byte *)"false";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar6);
    if ((bVar6) || ((bVar1 == 0x4e && (pbVar2[1] == 0)))) goto LAB_0816c6c8;
    if (bVar1 == 0x6e) {
      if (pbVar2[1] == 0) goto LAB_0816c6c8;
      if (pbVar2[1] != 0x6f) goto LAB_0816c728;
    }
    else if ((bVar1 != 0x4e) || (pbVar2[1] != 0x4f)) goto LAB_0816c728;
    if (pbVar2[2] != 0) {
LAB_0816c728:
      ERR_put_error(0x22,0x6e,0x68,"v3_utl.c",0xe5);
      ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value);
      return 0;
    }
  }
LAB_0816c6c8:
  *asn1_bool = 0;
  return 1;
}

