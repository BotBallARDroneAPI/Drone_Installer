/// ATCommand.h
#ifndef DRONECONSTANTS_H
#define DRONECONSTANTS_H
#include <string>

const std::string DRONE_IP =  "192.168.1.1";

const int NAVIGATION_DATA_PORT = 5554;
const int VIDEO_DATA_PORT = 5555;
const int ATCOMMAND_PORT = 5556;
const int CONFIG_DATA_PORT = 5559;

const unsigned int INTERVAL = 100;

//Controller Constants
const std::string ATCONFIG_COMMAND = "AT*CONFIG=";
const std::string ATCTRL_COMMAND = "AT*CTRL=";
const std::string ATFLAT_TRIM_COMMAND = "AT*FTRIM=";
const std::string ATSTATE_COMMAND = "AT*REF="; //LAND TAKEOFF TOGGLE_EMERGENCY
const std::string ATMOVE_COMMAND = "AT*PCMD=";
const std::string ATWATCHDOG_COMMAND = "AT*COMWDG=";

const std::string TAKEOFF_ARG = ",290718208";
const std::string LAND_ARG = ",290717696";
const std::string EMERGENCY_ARG = ",290717952";

const int DEFAULT_MAX_ALTITUDE = 4572; //altitude max 4572 mm = 15 ft
const std::string MAX_ALTITUDE_ARG  = ",\"control:altitude_max\",\"";

const int DEFAULT_MAX_VERTICAL_SPEED = 2000; // maximum vertical speed 2000mm/s = 2m/s
const std::string MAX_VERTICAL_SPEED = ",\"control:control_vz_max\",\"";  

const float DEFAULT_MAX_EULER_ANGLE = 0.52; //In Radians .52 Rads = 30 Deg
const std::string MAX_EULER_ANGLE = "\"control:euler_angle_max\",\"";

const float DEFAULT_MAX_YAW_SPEED = 6.00; //maximum yaw speed = 6rad/s ~= 343deg/s
const std::string MAX_YAW_SPEED = ",\"control:control_yaw\",\"";

const int DEFAULT_VIDEO_BITRATE = 500;
const std::string VIDEO_BITRATE_CONTROL_MODE = "\"video:_control_mode\",\"";
const std::string VIDEO_BITRATE = "\"video:bitrate\",\"";

const std::string MAC_ADDRESS = ",\"network:owner_mac\",\"";

const std::string SHELL_INSIDE_MODE_ARG = ",\"control:flight_without_shell\",\"FALSE\"";
const std::string SHELL_OUTSIDE_MODE_ARG = ",\"control:flight_without_shell\",\"TRUE\"";

const std::string CONTROL_LEVEL = ",\"control:control_level\",\"";

const std::string MINIMAL_NAV_DATA_ARG = ",\"general:navdata_demo\",\"TRUE\"";
const std::string ALL_NAV_DATA_ARG = ",\"general:navdata_demo\",\"FALSE\"";

const std::string REQUEST_CONFIG_DATA = ",4,0";
const std::string RESET_ACKNOWLEDGE_BIT_ARG = ",5,0";

const std::string REQUEST_VISION_TAG_DATA_ARG = ",\"general:navdata_options\",\"65537\"";

const std::string VIDEO_ENABLE_ARG = ",\"general:video_enable\",\"TRUE\"";
const std::string VIDEO_DISABLE_ARG = ",\"general:video_enable\",\"FALSE\"";

const std::string FRONT_CAMERA = ",\"video:video_channel\",\"0\"";
const std::string DOWN_CAMERA = ",\"video:video_channel\",\"1\"";

const std::string ULTRASOUND_CHANNEL_A_ARG = ",\"pic:ultrasound_freq\",\"8\"";
const std::string ULTRASOUND_CHANNEL_B_ARG = ",\"pic:ultrasound_freq\",\"7\"";

const std::string ENEMY_COLOR_GREEN_ARG = ",\"detect:enemy_colors\",\"1\"";
const std::string ENEMY_COLOR_YELLOW_ARG = ",\"detect:enemy_colors\",\"2\"";
const std::string ENEMY_COLOR_BLUE_ARG = ",\"detect:enemy_colors\",\"3\"";

const std::string DETECT_TYPE_STRIPE_ARG = ",\"detect:detect_type\"),\"6\"";
const std::string DETECT_TYPE_NONE_ARG = ",\"detect:detect_type\"),\"3\"";
const std::string DETECT_TYPE_ROUNDEL_ARG = ",\"detect:detect_type\"),\"12\"";
const std::string DETECT_TYPE_ENEMIES_FRONT_CAMERA_ARG = ",\"detect:detect_type\"),\"13\"";

const std::string GROUND_STRIPE_YELLOW_BLUE_ARG = ",\"detect:enemy_colors\",\"0x11\"";
const std::string GROUND_STRIPE_ORANGE_GREEN_ARG = ",\"detect:enemy_colors\",\"0x10\"";

const std::string FLYING_MODE_NORMAL_ARG = ",\"control:flying_mode\",\"0\"";
const std::string FLYING_MODE_HOVER_ON_ROUNDEL_ARG = ",\"control:flying_mode\",\"1\"";
const std::string FLYING_MODE_HOVER_ON_ORIENTED_ROUNDEL_ARG = ",\"control:flying_mode\",\"2\"";

const std::string VIDEO_CONTROL_MODE_DISABLE_ARG = ",\"video:bitrate_ctrl_mode\",\"0\"";

const std::string ANIMATION_CONTROL_ARG = ",\"control:flight_anim\",\"";
const std::string LED_ANIMATION_CONTROL_ARG = ",\"leds:leds_anim\",\"";

// ARDroneAPI Constants
const float DRIFT_TOLERANCE = 0.001;
const float TIMESTAMP_PER_SECOND = float(1)/float(1000);
const int MILIMETERS_PER_METER = 1000;

//VideoDecoder
const int kPictureFormatCIF = 1;
const int kPictureFormatVGA = 2;

const int CONST_BlockWidth = 8;
const int CONST_BlockSize = 64;

const int CONST_WidthCif = 88;
const int CONST_HeightCif = 72;

const int CONST_WidthVga = 160;
const int CONST_HeightVga = 120;

const int CONST_TableQuantization = 31;

const int FIX_0_298631336 = 2446;
const int FIX_0_390180644 = 3196;
const int FIX_0_541196100 = 4433;
const int FIX_0_765366865 = 6270;
const int FIX_0_899976223 = 7373;
const int FIX_1_175875602 = 9633;
const int FIX_1_501321110 = 12299;
const int FIX_1_847759065 = 15137;
const int FIX_1_961570560 = 16069;
const int FIX_2_053119869 = 16819;
const int FIX_2_562915447 = 20995;
const int FIX_3_072711026 = 25172;

const int CONST_BITS = 13;
const int PASS1_BITS = 1;

const std::string NUM_VERSION_CONFIG_TYPE = "general:num_version_config";
const std::string NUM_VERSION_MB_TYPE = "general:num_version_mb";
const std::string NUM_VERSION_SOFT_TYPE = "general:num_version_soft";
const std::string DRONE_SERIAL_TYPE = "general:drone_serial";
const std::string SOFT_BUILD_DATE_TYPE = "general:soft_build_date";
const std::string MOTOR1_SOFT_TYPE = "general:motor1_soft";
const std::string MOTOR1_HARD_TYPE = "general:motor1_hard";
const std::string MOTOR1_SUPPLIER_TYPE = "general:motor1_supplier";
const std::string MOTOR2_SOFT_TYPE = "general:motor2_soft";
const std::string MOTOR2_HARD_TYPE = "general:motor2_hard";
const std::string MOTOR2_SUPPLIER_TYPE = "general:motor2_supplier";
const std::string MOTOR3_SOFT_TYPE = "general:motor3_soft";
const std::string MOTOR3_HARD_TYPE = "general:motor3_hard";
const std::string MOTOR3_SUPPLIER_TYPE = "general:motor3_supplier";
const std::string MOTOR4_SOFT_TYPE = "general:motor4_soft";
const std::string MOTOR4_HARD_TYPE = "general:motor4_hard";
const std::string MOTOR4_SUPPLIER_TYPE = "general:motor4_supplier";
const std::string ARDRONE_NAME_TYPE = "general:ardrone_name";
const std::string FLYING_TIME_TYPE = "general:flying_time";
const std::string NAVDATA_DEMO_TYPE = "general:navdata_demo";
const std::string COM_WATCHDOG_TYPE = "general:com_watchdog";
const std::string VIDEO_ENABLE_TYPE = "general:video_enable";
const std::string VISION_ENABLE_TYPE = "general:vision_enable";
const std::string VBAT_MIN_TYPE = "general:vbat_min";
const std::string ACCS_OFFSET_TYPE = "control:accs_offset";
const std::string ACCS_GAINS_TYPE = "control:accs_gains";
const std::string GYROS_OFFSET_TYPE = "control:gyros_offset";
const std::string GYROS_GAINS_TYPE = "control:gyros_gains";
const std::string GYROS110_OFFSET_TYPE = "control:gyros110_offset";
const std::string GYROS110_GAINS_TYPE = "control:gyros110_gains";
const std::string MAGNETO_OFFSET_TYPE = "control:magneto_offset";
const std::string MAGNETO_RADIUS_TYPE = "control:magneto_radius";
const std::string GYRO_OFFSET_THR_X_TYPE = "control:gyro_offset_thr_x";
const std::string GYRO_OFFSET_THR_Y_TYPE = "control:gyro_offset_thr_y";
const std::string GYRO_OFFSET_THR_Z_TYPE = "control:gyro_offset_thr_z";
const std::string PWM_REF_GYROS_TYPE = "control:pwm_ref_gyros";
const std::string OSCTUN_VALUE_TYPE = "control:osctun_value";
const std::string OSCTUN_TEST_TYPE = "control:osctun_test";
const std::string ALTITUDE_MAX_TYPE = "control:altitude_max";
const std::string ALTITUDE_MIN_TYPE = "control:altitude_min";
const std::string OUTDOOR_TYPE = "control:outdoor";
const std::string FLIGHT_WITHOUT_SHELL_TYPE = "control:flight_without_shell";
const std::string CONTROL_LEVEL_TYPE = "control:control_level";
const std::string AUTONOMOUS_FLIGHT_TYPE = "control:autonomous_flight";
const std::string FLIGHT_ANIM_TYPE = "control:flight_anim";
const std::string EULER_ANGLE_MAX_TYPE = "control:euler_angle_max";
const std::string CONTROL_IPHONE_TILT_TYPE = "control:control_iphone_tilt";
const std::string CONTROL_VZ_MAX_TYPE = "control:control_vz_max";
const std::string CONTROL_YAW_TYPE = "control:control_yaw";
const std::string MANUAL_TRIM_TYPE = "control:manual_trim";
const std::string INDOOR_EULER_ANGLE_TYPE = "control:indoor_euler_angle_max";
const std::string INDOOR_CONTROL_VZ_MAX_TYPE = "control:indoor_control_vz_max";
const std::string INDOOR_CONTROL_YAW_TYPE = "control:indoor_control_yaw";
const std::string OUTDOOR_EULER_ANGLE_MAX_TYPE = "control:outdoor_euler_angle_max";
const std::string OUTDOOR_CONTROL_VZ_MAX_TYPE = "control:outdoor_control_vz_max";
const std::string OUTDOOR_CONTROL_YAW_TYPE = "control:outdoor_control_yaw";
const std::string FLYING_MODE_TYPE = "control:flying_mode";
const std::string HOVERING_RANGE_TYPE = "control:hovering_range";
const std::string SSID_SINGLE_PLAYER_TYPE = "network:ssid_single_player";
const std::string SSID_MULTIPLAYER_TYPE = "network:ssid_multi_player";
const std::string WIFI_MODE_TYPE = "network:wifi_mode";
const std::string WIFI_RATE_TYPE = "network:wifi_rate";
const std::string OWNER_MAC_TYPE = "network:owner_mac";
const std::string ULTRASOUND_FREQ_TYPE = "pic:ultrasound_freq";
const std::string ULTRASOUND_WATCHDOG_TYPE = "pic:ultrasound_watchdog";
const std::string PIC_VERSION_TYPE = "pic:pic_version";
const std::string OUTPUT_TYPE = "syslog:output";
const std::string MAX_SIZE_TYPE = "syslog:max_size";
const std::string NB_FILES_TYPE = "syslog:nb_files";
const std::string LOCALTIME_TYPE = "general:localtime";
const std::string NAVDATA_OPTIONS_TYPE = "general:navdata_options";
const std::string CAMIF_FPS_TYPE = "video:camif_fps";
const std::string CAMIF_BUFFERS_TYPE = "video:camif_buffers";
const std::string NUM_TRACKERS_TYPE = "video:num_trackers";
const std::string CODEC_FPS_TYPE = "video:codec_fps";
const std::string VIDEO_CODEC_TYPE = "video:video_codec";
const std::string VIDEO_SLICES_TYPE = "video:video_slices";
const std::string VIDEO_LIVE_SOCKET_TYPE = "video:video_live_socket";
const std::string VIDEO_STORAGE_SPACE_TYPE = "video:video_storage_space";
const std::string BITRATE_TYPE = "video:bitrate";
const std::string MAX_BITRATE_TYPE = "video:max_bitrate";
const std::string BITRATE_CTRL_MODE_TYPE = "video:bitrate_ctrl_mode";
const std::string BITRATE_STORAGE_TYPE = "video:bitrate_storage";
const std::string VIDEO_CHANNEL_TYPE = "video:video_channel";
const std::string VIDEO_ON_USB_TYPE = "video:video_on_usb";
const std::string VIDEO_FILE_INDEX_TYPE = "video:video_file_index";
const std::string LEDS_ANIM_TYPE = "leds:leds_anim";
const std::string ENEMY_COLORS_TYPE = "detect:enemy_colors";
const std::string GROUNDSTRIPE_COLORS_TYPE = "detect:groundstripe_colors";
const std::string ENEMY_WITHOUT_SHELL_TYPE = "detect:enemy_without_shell";
const std::string DETECT_TYPE_TYPE = "detect:detect_type";
const std::string DETECTIONS_SELECT_TYPE = "detect:detections_select_h";
const std::string DETECTIONS_SELECT_V_HSYNC_TYPE = "detect:detections_select_v_hsync";
const std::string DETECTIONS_SELECT_V_TYPE = "detect:detections_select_v";
const std::string USERBOX_CMD_TYPE = "userbox:userbox_cmd";
const std::string LATITUDE_TYPE = "gps:latitude";
const std::string LONGITUDE_TYPE = "gps:longitude";
const std::string ALTITUDE_TYPE = "gps:altitude";
const std::string APPLICATION_ID_TYPE = "custom:application_id";
const std::string APPLICATION_DESC_TYPE = "custom:application_desc";
const std::string PROFILE_ID_TYPE = "custom:profile_id";
const std::string PROFILE_DESC_TYPE = "custom:profile_desc";
const std::string SESSION_ID_TYPE = "custom:session_id";
const std::string SESSION_DESC_TYPE = "custom:session_desc";

#endif
