
int X509V3_get_value_bool(CONF_VALUE *value,int *asn1_bool)

{
  char cVar1;
  int iVar2;
  char *__s1;
  
  __s1 = value->value;
  if (__s1 != (char *)0x0) {
    iVar2 = strcmp(__s1,"TRUE");
    if (((((iVar2 == 0) || (iVar2 = strcmp(__s1,"true"), iVar2 == 0)) ||
         ((cVar1 = *__s1, cVar1 == 'Y' && (__s1[1] == '\0')))) ||
        (((cVar1 == 'y' && (__s1[1] == '\0')) ||
         ((cVar1 == 'Y' && (((__s1[1] == 'E' && (__s1[2] == 'S')) && (__s1[3] == '\0')))))))) ||
       (((cVar1 == 'y' && (__s1[1] == 'e')) && ((__s1[2] == 's' && (__s1[3] == '\0')))))) {
      *asn1_bool = 0xff;
      return 1;
    }
    iVar2 = strcmp(__s1,"FALSE");
    if (((iVar2 == 0) || (iVar2 = strcmp(__s1,"false"), iVar2 == 0)) ||
       (((((cVar1 == 'N' && (__s1[1] == '\0')) || ((cVar1 == 'n' && (__s1[1] == '\0')))) ||
         ((cVar1 == 'N' && ((__s1[1] == 'O' && (__s1[2] == '\0')))))) ||
        ((cVar1 == 'n' && ((__s1[1] == 'o' && (__s1[2] == '\0')))))))) {
      *asn1_bool = 0;
      return 1;
    }
  }
  ERR_put_error(0x22,0x6e,0x68,"v3_utl.c",0xe5);
  ERR_add_error_data(6,"section:",value->section,",name:",value->name,",value:",value->value);
  return 0;
}

