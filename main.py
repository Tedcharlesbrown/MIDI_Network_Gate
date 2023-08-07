import mido
# import rtmidi

dict_commands = {
    "01": "GO",
    "02": "PAUSE",
    "03": "RESUME",
    "06": "SUB/GRANDMASTER",
    "07": "MACRO"
}

def parse_sysex(sysex: str):
    parts = sysex.split(" ")

    parts.pop(0) # REMOVE F0
    parts.pop(0) # REMOVE 7F
    parts.pop(-1) # REMOVE LAST 7F

    device_id = str(int(parts[0],16))
    parts.pop(0) # REMOVE DEVICE ID

    parts.pop(0) # REMOVE 02
    parts.pop(0) # REMOVE 01

    command = dict_commands.get(parts[0], None)
    parts.pop(0) # REMOVE COMMAND

    # --------------------------- GET CUE WHOLE NUMBER --------------------------- #
    cue_number = ""
    cue_length = 0
    for part in parts:
        if part != "00" and part != "2E": #IF PART IS NOT END OF INT OR DECIMAL DELIM
            cue_number += part.removeprefix("3")
            cue_length+= 1
        elif part == "2E":
            cue_number += "."
            cue_length+= 1
        else:
            cue_length+= 1
            break

    parts = parts[cue_length:]

    # ------------------------------- GET CUE LIST ------------------------------- #
    cue_list = ""
    for part in parts:
        cue_list += part.removeprefix("3")

    print(device_id,command,cue_list,cue_number)






# ---------------------------------------------------------------------------- #
#                                     MAIN                                     #
# ---------------------------------------------------------------------------- #


# List all input ports
in_ports = mido.get_input_names()
out_ports = mido.get_output_names()
print('Available input ports:', in_ports)
print('Available output ports:', out_ports)

midi_input_port = in_ports[1]
midi_output_port = out_ports[1]

# with mido.open_input(midi_input_port) as inport:
#     print(f"Listening to {midi_input_port}... Press Ctrl+C to exit.")
#     for msg in inport:
#         if msg.type == 'sysex':
#             parse_sysex(msg.hex())

with mido.open_input(midi_output_port) as outport:
    print(f"Outputing to {midi_output_port}... Press Ctrl+C to exit.")





