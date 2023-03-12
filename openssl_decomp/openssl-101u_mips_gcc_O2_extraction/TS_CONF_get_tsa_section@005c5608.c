
int TS_CONF_get_tsa_section(undefined4 param_1,int param_2)

{
  if ((param_2 == 0) &&
     (param_2 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,"tsa","default_tsa"), param_2 == 0)
     ) {
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"variable lookup failed for %s::%s\n","tsa",
               "default_tsa");
  }
  return param_2;
}

