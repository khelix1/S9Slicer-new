# How to Use S9Slicer

## Step 1: Load a Model
```cpp
Slicer slicer;
slicer.loadModel("model.stl");
```

## Step 2: Generate Slices and Paths
```cpp
slicer.generateLayers();
slicer.generatePerimeters();
slicer.generateInfill();
```

## Step 3: Export G-code
```cpp
GCodeGenerator gcode;
gcode.setOutputFile("output.gcode");
for (const auto& layer : slicer.getLayers()) {
    gcode.emitLayer(layer, z);
}
gcode.emitFooter();
```

## Optional: Add Fan Commands
```cpp
FanControlManager fan;
fan.registerExtrusionMove(...);
auto cmds = fan.getFanCommands();
```
