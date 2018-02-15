function CodeDefine() { 
this.def = new Array();
this.def["IsrOverrun"] = {file: "ert_main_c.html",line:23,type:"var"};
this.def["OverrunFlag"] = {file: "ert_main_c.html",line:24,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:25,type:"fcn"};
this.def["stopRequested"] = {file: "ert_main_c.html",line:52,type:"var"};
this.def["main"] = {file: "ert_main_c.html",line:53,type:"fcn"};
this.def["Arduino_pid_program_B"] = {file: "Arduino_pid_program_c.html",line:25,type:"var"};
this.def["Arduino_pid_program_DW"] = {file: "Arduino_pid_program_c.html",line:28,type:"var"};
this.def["Arduino_pid_program_M_"] = {file: "Arduino_pid_program_c.html",line:31,type:"var"};
this.def["Arduino_pid_program_M"] = {file: "Arduino_pid_program_c.html",line:32,type:"var"};
this.def["Arduino_pid_program_step"] = {file: "Arduino_pid_program_c.html",line:36,type:"fcn"};
this.def["Arduino_pid_program_initialize"] = {file: "Arduino_pid_program_c.html",line:69,type:"fcn"};
this.def["Arduino_pid_program_terminate"] = {file: "Arduino_pid_program_c.html",line:108,type:"fcn"};
this.def["B_Arduino_pid_program_T"] = {file: "Arduino_pid_program_h.html",line:48,type:"type"};
this.def["DW_Arduino_pid_program_T"] = {file: "Arduino_pid_program_h.html",line:54,type:"type"};
this.def["codertarget_arduinobase_inter_T"] = {file: "Arduino_pid_program_types_h.html",line:30,type:"type"};
this.def["cell_wrap_Arduino_pid_program_T"] = {file: "Arduino_pid_program_types_h.html",line:39,type:"type"};
this.def["codertarget_arduinobase_int_d_T"] = {file: "Arduino_pid_program_types_h.html",line:54,type:"type"};
this.def["P_Arduino_pid_program_T"] = {file: "Arduino_pid_program_types_h.html",line:59,type:"type"};
this.def["RT_MODEL_Arduino_pid_program_T"] = {file: "Arduino_pid_program_types_h.html",line:62,type:"type"};
this.def["Arduino_pid_program_P"] = {file: "Arduino_pid_program_data_c.html",line:24,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:82,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:87,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:92,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:99,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:106,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:113,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:120,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:127,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:134,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:152,type:"type"};
this.def["getLoopbackIP"] = {file: "MW_target_hardware_resources_h.html",line:10,type:"var"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["Arduino_pid_program_c.html"] = "../Arduino_pid_program.c";
	this.html2Root["Arduino_pid_program_c.html"] = "Arduino_pid_program_c.html";
	this.html2SrcPath["Arduino_pid_program_h.html"] = "../Arduino_pid_program.h";
	this.html2Root["Arduino_pid_program_h.html"] = "Arduino_pid_program_h.html";
	this.html2SrcPath["Arduino_pid_program_private_h.html"] = "../Arduino_pid_program_private.h";
	this.html2Root["Arduino_pid_program_private_h.html"] = "Arduino_pid_program_private_h.html";
	this.html2SrcPath["Arduino_pid_program_types_h.html"] = "../Arduino_pid_program_types.h";
	this.html2Root["Arduino_pid_program_types_h.html"] = "Arduino_pid_program_types_h.html";
	this.html2SrcPath["Arduino_pid_program_data_c.html"] = "../Arduino_pid_program_data.c";
	this.html2Root["Arduino_pid_program_data_c.html"] = "Arduino_pid_program_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["MW_target_hardware_resources_h.html"] = "../MW_target_hardware_resources.h";
	this.html2Root["MW_target_hardware_resources_h.html"] = "MW_target_hardware_resources_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","Arduino_pid_program_c.html","Arduino_pid_program_h.html","Arduino_pid_program_private_h.html","Arduino_pid_program_types_h.html","Arduino_pid_program_data_c.html","rtwtypes_h.html","rtmodel_h.html","MW_target_hardware_resources_h.html"];
