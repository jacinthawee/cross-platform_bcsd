
/* WARNING: Removing unreachable block (ram,0x0058d17c) */

int X509V3_get_value_bool(CONF_VALUE *value,int *asn1_bool)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = value->value;
  if (pcVar4 == (char *)0x0) goto LAB_0058d1c8;
  iVar3 = (*(code *)PTR_strcmp_006aac20)(pcVar4,&DAT_0066dff8);
  if (((iVar3 == 0) || (iVar3 = (*(code *)PTR_strcmp_006aac20)(pcVar4,&DAT_0066e008), iVar3 == 0))
     || ((cVar1 = *pcVar4, cVar1 == 'Y' && (pcVar4[1] == '\0')))) goto LAB_0058d0ac;
  if (cVar1 == 'y') {
    if (pcVar4[1] == '\0') goto LAB_0058d0ac;
    if ((pcVar4[1] == 'e') && (pcVar4[2] == 's')) {
      cVar2 = pcVar4[3];
      goto LAB_0058d100;
    }
  }
  else if (((cVar1 == 'Y') && (pcVar4[1] == 'E')) && (pcVar4[2] == 'S')) {
    cVar2 = pcVar4[3];
LAB_0058d100:
    if (cVar2 == '\0') {
LAB_0058d0ac:
      *asn1_bool = 0xff;
      return 1;
    }
  }
  iVar3 = (*(code *)PTR_strcmp_006aac20)(pcVar4,"FALSE");
  if (((iVar3 != 0) && (iVar3 = (*(code *)PTR_strcmp_006aac20)(pcVar4,"false"), iVar3 != 0)) &&
     ((cVar1 != 'N' || (pcVar4[1] != '\0')))) {
    if (cVar1 == 'n') {
      if (pcVar4[1] == '\0') goto LAB_0058d15c;
      if (pcVar4[1] != 'o') goto LAB_0058d1c8;
    }
    else if ((cVar1 != 'N') || (pcVar4[1] != 'O')) goto LAB_0058d1c8;
    if (pcVar4[2] != '\0') {
LAB_0058d1c8:
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6e,0x68,"v3_utl.c",0xe5);
      (*(code *)PTR_ERR_add_error_data_006a9264)
                (6,"section:",value->section,",name:",value->name,",value:",value->value);
      return 0;
    }
  }
LAB_0058d15c:
  *asn1_bool = 0;
  return 1;
}

