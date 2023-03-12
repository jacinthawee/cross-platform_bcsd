
int TS_CONF_get_tsa_section(undefined4 param_1,int param_2)

{
  if ((param_2 == 0) &&
     (param_2 = (*(code *)PTR_NCONF_get_string_006a7fa8)(param_1,"tsa","default_tsa"), param_2 == 0)
     ) {
    (*(code *)PTR___fprintf_chk_006aaa8c)
              (*(undefined4 *)PTR_stderr_006aac00,1,"variable lookup failed for %s::%s\n","tsa",
               "default_tsa");
  }
  return param_2;
}

